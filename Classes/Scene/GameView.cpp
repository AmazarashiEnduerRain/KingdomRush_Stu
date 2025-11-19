//
// Created by 20619 on 2025/11/19.
//

#include "GameView.h"
#include "TransitionGame.h"
#include "WelcomeScene.h"
#include "Sprite/MapFlag.h"
#include "Road/Road.h"
#include "Layer/GameViewMenu.h"
#include "Data/GameManager.h"
#include "Sprite/RespirationSprite.h"
#include "Data/SoundManager.h"
USING_NS_CC;

Scene* GameView::createScene(){
    auto scene = Scene::create();
    auto layer = GameView::create();//地图层
	auto menuLayer = GameViewMenu::create();//UI层

    scene->addChild(layer);
	scene->addChild(menuLayer);
    return scene;
}

bool GameView::init(){
    if ( !Layer::init() ) return false;

	instance = GameManager::getInstance();
	winSize = Director::getInstance()->getWinSize();

	bgSprite = Sprite::createWithSpriteFrameName("MapBackground.png");
	bgSprite->setAnchorPoint(Vec2::ZERO);
	bgSprite->setPosition(Vec2::ZERO);
	addChild(bgSprite);

	mapFlagPointVector.push_back(Point(375,775));
	mapFlagPointVector.push_back(Point(495,735));
	mapFlagPointVector.push_back(Point(510,620));
	mapFlagPointVector.push_back(Point(370,575));
	mapFlagPointVector.push_back(Point(205,505));
	mapFlagPointVector.push_back(Point(455,305));
	mapFlagPointVector.push_back(Point(690,420));
	mapFlagPointVector.push_back(Point(855,254));
	mapFlagPointVector.push_back(Point(1020,340));
	mapFlagPointVector.push_back(Point(934,490));
	mapFlagPointVector.push_back(Point(830,560));
	mapFlagPointVector.push_back(Point(795,710));
	mapFlagPointVector.push_back(Point(910,770));
	mapFlagPointVector.push_back(Point(1015,770));

	addRoad();
	addMapFlag();

	//进行聚焦（集中到新解锁的关卡位置）
	int newReady = UserDefault::getInstance()->getIntegerForKey(instance->LEVELX_NEWDOWN,0);

	//计算目标位置
	Point location = Point();
	location.x = winSize.width / 2 - mapFlagPointVector.at(newReady).x;
	location.y = winSize.height / 2 - mapFlagPointVector.at(newReady).y;
	//位置修正，防止移出
	auto bgSpriteCurrSize = bgSprite->getBoundingBox().size;
	location.x = MIN(location.x, bgSpriteCurrSize.width * bgSprite->getAnchorPoint().x);
	location.x = MAX(location.x, -bgSpriteCurrSize.width + winSize.width + bgSpriteCurrSize.width * bgSprite->getAnchorPoint().x);
	location.y = MIN(location.y, bgSpriteCurrSize.height * bgSprite->getAnchorPoint().y);
	location.y = MAX(location.y, -bgSpriteCurrSize.height + winSize.height + bgSpriteCurrSize.height * bgSprite->getAnchorPoint().y);
	this->setPosition(location);

	auto listener = EventListenerTouchAllAtOnce::create();
	listener->onTouchesBegan = CC_CALLBACK_2(GameView::onTouchesBegan, this);// 触摸开始时触发
	listener->onTouchesMoved = CC_CALLBACK_2(GameView::onTouchesMoved, this);// 触摸移动时触发
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, bgSprite);

	auto listenerkeyPad = EventListenerKeyboard::create();
	listenerkeyPad->onKeyReleased = CC_CALLBACK_2(GameView::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerkeyPad, this);

	SoundManager::playGameTheme1();
    return true;
}

void GameView::onEnterTransitionDidFinish(){
	int newReady = UserDefault::getInstance()->getIntegerForKey(instance->LEVELX_NEWDOWN,0); //检查是否新解锁了关卡
	if(newReady <= 12){//最多13关
		if(UserDefault::getInstance()->getIntegerForKey(instance->SLOTX_DOWNCOUNT,0) != newReady){
			UserDefault::getInstance()->setIntegerForKey(instance->SLOTX_DOWNCOUNT,newReady);//数据更新
			mapFlagVector.at(newReady - 1)->changeType(0);//改变上一关的状态
			auto sequence = Sequence::create(
				CallFuncN::create(CC_CALLBACK_0(MapFlag::startSuccessAnimation, mapFlagVector.at(newReady - 1)))
				,CallFuncN::create(CC_CALLBACK_0(Road::buildRoadAnimation, road,newReady - 1))
				,DelayTime::create(1.5f)
				,CallFuncN::create(CC_CALLBACK_0(GameView::addNewMapFlag,this ,newReady)),NULL);
			runAction(sequence);
		}
	}
}

void GameView::addNewMapFlag(int num){
	auto mapFlag = MapFlag::createWithLevel(num);
	mapFlag->setPosition(mapFlagPointVector.at(num));
	addChild(mapFlag);

	mapFlagVector.pushBack(mapFlag);
	mapFlag->startDropdownAnimation();
}

void GameView::addRoad(){
	road = Road::create();
	road->setPosition(Point(635,500));//道路层的基准坐标
	addChild(road);
}

void GameView::addMapFlag(){
	int count = UserDefault::getInstance()->getIntegerForKey(instance->SLOTX_DOWNCOUNT,0);
	for(int i = 0;i <= count;i++){
		auto mapFlag = MapFlag::createWithLevel(i);
		mapFlag->setPosition(mapFlagPointVector.at(i));
		mapFlagVector.pushBack(mapFlag);

		if(i == count) mapFlag->setStarClose();//最新的一关是未挑战状态

		addChild(mapFlag);
	}
	if(UserDefault::getInstance()->getIntegerForKey(instance->LEVELX_NEWDOWN,0) == 0){
		auto respirationSprite = RespirationSprite::createRespirationSprite("mapBalloon_starthere.png");
		respirationSprite->setPosition(Point(375,855));//若第一次游玩，添加一个呼吸动画提示
		addChild(respirationSprite);
	}
}

void GameView::onTouchesMoved(const std::vector<Touch*>& touches, Event  *event){
	if(touches.size() == 1){
        auto touch = touches[0];//此时是单点移动，故touches[0]即能够获得触摸对象
        auto diff = touch->getDelta();
        auto currentPos = this->getPosition();
        auto pos = currentPos + diff;

        auto bgSpriteCurrSize = bgSprite->getBoundingBox().size;
        pos.x = MIN(pos.x, bgSpriteCurrSize.width * bgSprite->getAnchorPoint().x);
        pos.x = MAX(pos.x, -bgSpriteCurrSize.width + winSize.width + bgSpriteCurrSize.width * bgSprite->getAnchorPoint().x);
        pos.y = MIN(pos.y, bgSpriteCurrSize.height * bgSprite->getAnchorPoint().y);
        pos.y = MAX(pos.y, -bgSpriteCurrSize.height + winSize.height + bgSpriteCurrSize.height * bgSprite->getAnchorPoint().y);

        this->setPosition(pos);
    }
}

void GameView::onTouchesBegan(const std::vector<Touch*>& touches, Event  *event){}

void GameView::onKeyReleased(EventKeyboard::KeyCode keycode, Event* event){
	if(keycode==EventKeyboard::KeyCode::KEY_BACK){
		auto scene = WelcomeScene::createScene();//返回欢迎界面
		Director::getInstance()->replaceScene(TransitionGame::create(2.0f,scene));
	}
}
