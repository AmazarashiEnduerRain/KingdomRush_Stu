//
// Created by 20619 on 2025/11/20.
//
#include "TowerScene.h"
#include "Data/SoundManager.h"
USING_NS_CC;

Scene* TowerScene::createScene(){
    auto scene = Scene::create();
    auto towerInfLayer = TowerScene::create();
    scene->addChild(towerInfLayer);
    return scene;
}

bool TowerScene::init(){
    if ( !Layer::init() ) return false;

	visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin(); //手机可视屏幕的原点坐标

	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(TowerScene::onTouchBegan, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(TowerScene::onTouchEnded, this);

	//背景平铺
	for(int i = 0;i < 4;i++){
		for(int j = 0;j < 5;j++){
			auto sprite = Sprite::createWithSpriteFrameName("encyclopedia_bgTile.png");
			sprite->setPosition(Point(i * 310,j * 150));
			sprite->setAnchorPoint(Point(0,0));
			addChild(sprite);
		}
	}

	//书本背景
    auto bookRight = Sprite::createWithSpriteFrameName("encyclopedia_book_pg.png");
    bookRight->setPosition(Vec2(visibleSize.width * 3 / 4 + origin.x, visibleSize.height / 2 + origin.y));
    auto bookLeft = Sprite::createWithSpriteFrameName("encyclopedia_book_pg.png");
    bookLeft->setPosition(Vec2(visibleSize.width / 4 + origin.x, visibleSize.height / 2 + origin.y));
	bookLeft->setFlippedX(true);
    this->addChild(bookRight, 1);
	this->addChild(bookLeft, 1);

	//关闭按钮
	auto closeBtnNormal = Sprite::createWithSpriteFrameName("encyclopedia_tow_creep_close_0001.png");
	auto closeBtnPressed = Sprite::createWithSpriteFrameName("encyclopedia_tow_creep_close_0001.png");
	auto closeBtnDisabled = Sprite::createWithSpriteFrameName("encyclopedia_tow_creep_close_0001.png");
	spriteCloseButton = MenuItemSprite::create(closeBtnNormal,closeBtnPressed,closeBtnDisabled,CC_CALLBACK_1(TowerScene::closeScene,this));
    auto closeTowerScene = Menu::create(spriteCloseButton,NULL);
	closeTowerScene->setPosition(Vec2(visibleSize.width - closeBtnNormal->getContentSize().width * 3 / 2  + origin.x,
								visibleSize.height + origin.y - closeBtnNormal->getContentSize().height / 2));
    this->addChild(closeTowerScene,2);

	//框框
	selectionFrame = Sprite::createWithSpriteFrameName("encyclopedia_creep_thumbs_frame_0002.png");
    selectionFrame->setPosition(Point(visibleSize.width * 0.17, visibleSize.height * 0.75));
	this->addChild(selectionFrame,3);

	//无效的拇指图标
	auto spriteCreepThumbNull = Sprite::createWithSpriteFrameName("encyclopedia_tower_thumbs_0121.png");

	//初始化缩略图标20个
	for(int i = 0; i < 20; i ++){
		auto temp1 = __String::createWithFormat("encyclopedia_tower_thumbs_01%02d.png",i + 1)->getCString();
		auto temp2 = __String::createWithFormat("encyclopedia_tower_01%02d.png",i + 1)->getCString();

		towerDesc[i] = TowerDesc::createTowerDesc(temp1);
		towerDesc[i]->setPosition(Point(visibleSize.width * (0.17 + (i % 4) * 0.085),
										visibleSize.height * (0.75 - ((i / 4) % 5) * 0.15)));
		towerDesc[i]->towerThumbFileName = temp1;
		towerDesc[i]->towerDescFileName = temp2;
		towerDesc[i]->id = i;

		_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener->clone(), towerDesc[i]);

		this->addChild(towerDesc[i],2);
	}

	//初始化右侧大图显示（默认显示第一个）
	bigSprite = Sprite::createWithSpriteFrameName(towerDesc[0]->towerDescFileName);
	bigSprite->setPosition(Vec2(visibleSize.width * 0.7,visibleSize.height * 0.75));
	this->addChild(bigSprite,2);

	//标题
    auto labelTitle = Label::createWithTTF("TOWERS", "Marker Felt.ttf", 24);
    labelTitle->setPosition(Vec2(visibleSize.width * 0.3, visibleSize.height * 6 / 7));
	labelTitle->setColor(Color3B(0,0,0));
    this->addChild(labelTitle, 2);

	//塔名称
	labelName = Label::createWithTTF("", "Marker Felt.ttf", 24);
    labelName->setPosition(Vec2(visibleSize.width * 0.7, visibleSize.height * 0.60));
	labelName->setColor(Color3B(0,0,0));
    this->addChild(labelName, 2);
	//左列属性标签
	labelAttackSpeed = Label::createWithTTF("", "Marker Felt.ttf", 16);
    labelAttackSpeed->setPosition(Vec2(visibleSize.width * 0.65, visibleSize.height * 0.50));
	labelAttackSpeed->setColor(Color3B(0,0,0));
    this->addChild(labelAttackSpeed, 2);
	labelAttackValue = Label::createWithTTF("", "Marker Felt.ttf", 16);
    labelAttackValue->setPosition(Vec2(visibleSize.width * 0.65, visibleSize.height * 0.45));
	labelAttackValue->setColor(Color3B(0,0,0));
    this->addChild(labelAttackValue, 2);
	labelAttackRange = Label::createWithTTF("", "Marker Felt.ttf", 16);
    labelAttackRange->setPosition(Vec2(visibleSize.width * 0.65, visibleSize.height * 0.40));
	labelAttackRange->setColor(Color3B(0,0,0));
    this->addChild(labelAttackRange, 2);

	//底部描述
    labelNotice = Label::createWithTTF("*", "Marker Felt.ttf", 16);
    labelNotice->setPosition(Vec2(visibleSize.width * 0.7, visibleSize.height * 0.15));
	labelNotice->setColor(Color3B(0,0,0));
	labelNotice->setLineBreakWithoutSpace(true);
	labelNotice->setDimensions(visibleSize.width / 3,visibleSize.height * 0.15);
    this->addChild(labelNotice, 2);

	ValueVector txt_vec = FileUtils::getInstance()->getValueVectorFromFile("tower.xml");
	int i = 0;
	for( auto& e : txt_vec){
		auto txt_map = txt_vec.at(i).asValueMap();
		int id_int = txt_map.at("id").asInt();
		if(id_int == i){ //从xml文件中读取，寻找到对应的配置块
			towerDesc[i]->towerName = txt_map.at("TowerName").asString();
			towerDesc[i]->attackSpeed = txt_map.at("AttackSpeed").asString();
			towerDesc[i]->attackValue = txt_map.at("AttackValue").asString();
			towerDesc[i]->attackRange = txt_map.at("AttackRange").asString();
			towerDesc[i]->note = txt_map.at("Note").asString();
		}else if(id_int == 100){
			labelAttackSpeed->setString(txt_map.at("AttackSpeed").asString());
			labelAttackValue->setString(txt_map.at("AttackValue").asString());
			labelAttackRange->setString(txt_map.at("AttackRange").asString());//id 100用于存储属性标题
		}
		i ++;
	}

	//属性值显示
	labelAttackSpeed1 = Label::createWithTTF("", "Marker Felt.ttf", 16);
    labelAttackSpeed1->setPosition(Vec2(visibleSize.width * 0.75, visibleSize.height * 0.50));
	labelAttackSpeed1->setColor(Color3B(0,0,0));
    this->addChild(labelAttackSpeed1, 2);
	labelAttackValue1 = Label::createWithTTF("", "Marker Felt.ttf", 16);
    labelAttackValue1->setPosition(Vec2(visibleSize.width * 0.75, visibleSize.height * 0.45));
	labelAttackValue1->setColor(Color3B(0,0,0));
    this->addChild(labelAttackValue1, 2);
	labelAttackRange1 = Label::createWithTTF("", "Marker Felt.ttf", 16);
    labelAttackRange1->setPosition(Vec2(visibleSize.width * 0.75, visibleSize.height * 0.40));
	labelAttackRange1->setColor(Color3B(0,0,0));
    this->addChild(labelAttackRange1, 2);

	//初始默认选中第一个防御塔图标
	bigSprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(towerDesc[0]->towerDescFileName));
	labelName->setString(towerDesc[0]->towerName);
	labelAttackSpeed1->setString(towerDesc[0]->attackSpeed);
	labelAttackValue1->setString(towerDesc[0]->attackValue);
	labelAttackRange1->setString(towerDesc[0]->attackRange);
	labelNotice->setString(towerDesc[0]->note);
	selectionFrame->setPosition(towerDesc[0]->getPosition());
	selectionFrame->setVisible(true);
	return true;
}

bool TowerScene::onTouchBegan(Touch* touch, Event* event){
	auto target = static_cast<TowerDesc*>(event->getCurrentTarget());
	Point locationInNode = target->convertTouchToNodeSpace(touch);
	Size size = target->towerDescPic->getContentSize();
	Rect rect = Rect(-size.width / 2, -size.height / 2, size.width, size.height);

	if (rect.containsPoint(locationInNode) && target->getParent()->isVisible()){
		SoundManager::playClickEffect();

		bigSprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(target->towerDescFileName));
		labelName->setString(target->towerName);
		labelAttackSpeed1->setString(target->attackSpeed);
		labelAttackValue1->setString(target->attackValue);
		labelAttackRange1->setString(target->attackRange);
		labelNotice->setString(target->note);

		moveFrame = MoveTo::create(0.1f,target->getPosition());//设置框的位移时间，位移目标地址
		selectionFrame->runAction(moveFrame);
		selectionFrame->setVisible(true);

		return true;
	}
	return false;
}

void TowerScene::onTouchEnded(Touch* touch, Event* event){return;}

void TowerScene::closeScene(Ref* pSender){
	SoundManager::playClickEffect();
	Director::getInstance()->popScene();
}