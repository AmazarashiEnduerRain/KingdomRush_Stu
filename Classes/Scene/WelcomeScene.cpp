//
// Created by 20619 on 2025/11/19.
//
#include "WelcomeScene.h"
#include "GameView.h"
#include "TransitionGame.h"
#include "Data/SoundManager.h"
#include "SimpleAudioEngine.h"
#include "Introduction/Information.h"
#include "Sprite/SlotMenu.h"
using namespace CocosDenshion;

Scene* WelcomeScene::createScene(){
    auto scene = Scene::create();
    auto layer = WelcomeScene::create();
    scene->addChild(layer);

    return scene;
}

bool WelcomeScene::init(){
    if ( !Layer::init() ) return false;

	visibleSize = Director::getInstance()->getVisibleSize();

	initBackGround();
	initLogo();
	initMenu_save();
	initButton_start();
	init_creditBtn();
	initSoundButton();

	//物理按键监听绑定
	auto listenerkeyPad = EventListenerKeyboard::create();
	listenerkeyPad->onKeyReleased = CC_CALLBACK_2(WelcomeScene::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerkeyPad, this);

    return true;
}

void WelcomeScene::onEnterTransitionDidFinish(){
	//场景完全进入后，播放序列动画：Logo的弹跳、闪光’开始按钮、制作者按钮的进场
	auto Sequence = Sequence::create(
		ScaleTo::create(0.5f,1.5f,1.5f),
		ScaleTo::create(0.2f,1.0f,1.0f),
		CallFuncN::create(CC_CALLBACK_0(WelcomeScene::initLogoAnimation, this)),
		CallFuncN::create(CC_CALLBACK_0(WelcomeScene::initButton_startAnimation, this)),
		CallFuncN::create(CC_CALLBACK_0(WelcomeScene::init_creditBtn_startAnimation, this)),NULL);
	sprite_Logo->runAction(Sequence);
}

void WelcomeScene::initBackGround(){
	auto sprite_background = Sprite::createWithSpriteFrameName("mainmenu_bg.png");
	sprite_background->setPosition(Point(visibleSize.width / 2,visibleSize.height / 2));
	addChild(sprite_background,-1);
}

void WelcomeScene::initLogo(){
	sprite_Logo = Sprite::createWithSpriteFrameName("logo.png");
	sprite_Logo->setAnchorPoint(Vec2::ANCHOR_MIDDLE);//锚点设置为图片中央
	point_Logo.x = visibleSize.width / 2;
	point_Logo.y = visibleSize.height - (sprite_Logo->getContentSize().height / 2);

	sprite_Logo->setScale(0.2f);//初始缩小，用于弹跳动画
	sprite_Logo->setPosition(point_Logo);
	addChild(sprite_Logo,9);
}

void WelcomeScene::initButton_start(){
	button_Start = Sprite::createWithSpriteFrameName("menu_startchain_0001.png");
	button_Start->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	button_Start->setVisible(false);

	button_Start->setPosition(point_Logo.x,point_Logo.y);//初始在logo位置处。从而有落下来的动画效果
	addChild(button_Start,1);

	auto button_Start_listener = EventListenerTouchOneByOne::create();
	button_Start_listener->onTouchBegan = [&](Touch* touch, Event* event){
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		Point locationInNode = target->convertTouchToNodeSpace(touch);
		Size size = target->getContentSize();
		Rect rect = Rect(40, 30, size.width - 80, size.height / 3 + 15);
		if (rect.containsPoint(locationInNode) && target->isVisible()){
			SoundManager::playClickEffect();
			target->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("menu_startchain_0002.png"));
			return true;
		}
		return false;
	};
	button_Start_listener->onTouchEnded = [&](Touch* touch, Event* event){
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		static_cast<Sprite*>(event->getCurrentTarget())->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("menu_startchain_0001.png"));

		button_credit->setVisible(false);//完成对开始按钮的点击后，隐藏制作人员按钮
		button_credit->runAction(MoveTo::create(0.3f, Point(point_Logo.x,point_Logo.y - 180)));
		button_Start->runAction(Sequence::create(
			DelayTime::create(0.3f),
			MoveTo::create(0.3f, Point(point_Logo.x,point_Logo.y)),NULL));//开始按钮和制作人员按钮收回Logo处
		button_Start->setVisible(false);
		setSaveMenuVisible();
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(button_Start_listener,button_Start);
}

void WelcomeScene::init_creditBtn(){
	button_credit = Sprite::createWithSpriteFrameName("menu_creditschain_0001.png");
	button_credit->setVisible(false);
	button_credit->setPosition(point_Logo.x,point_Logo.y - 180);
	addChild(button_credit,0);

	auto button_credit_listener = EventListenerTouchOneByOne::create();
	button_credit_listener->onTouchBegan = [&](Touch* touch, Event* event){
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		Point locationInNode = target->convertTouchToNodeSpace(touch);
		Size size = target->getContentSize();
		Rect rect = Rect(40, 30, size.width - 80, size.height / 3 + 15);
		if (rect.containsPoint(locationInNode) && target->isVisible()){
			SoundManager::playClickEffect();
			target->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("menu_creditschain_0002.png"));
			return true;
		}
		return false;
	};
	button_credit_listener->onTouchEnded = [&](Touch* touch, Event* event){
		static_cast<Sprite*>(event->getCurrentTarget())->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("menu_creditschain_0001.png"));
		Director::getInstance()->replaceScene(Information::createScene());//恢复制作人员按钮样式并进入制作人员介绍场景
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(button_credit_listener,button_credit);
}

void WelcomeScene::initSoundButton(){
	auto winSize = Director::getInstance()->getWinSize();
	SoundManager::playWelcomeBackMusic();

	Sprite* backMusic;//背景音乐按钮
	if(UserDefault::getInstance()->getIntegerForKey("backmusic",1) == 1)//0表示禁止BGM，1表示开启
		backMusic = Sprite::createWithSpriteFrameName("options_overlay_buttons_0001.png");
	else
		backMusic = Sprite::createWithSpriteFrameName("options_overlay_buttons_0002.png");
	backMusic->setPosition(Point(backMusic->getContentSize().width / 2  + 10 ,winSize.height - backMusic->getContentSize().height / 2 - 10));
	addChild(backMusic);
	auto button_backMusic_listener = EventListenerTouchOneByOne::create();
	button_backMusic_listener->onTouchBegan = [&](Touch* touch, Event* event){
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		Point locationInNode = target->convertTouchToNodeSpace(touch);
		Size size = target->getContentSize();
		Rect rect = Rect(0, 0, size.width, size.height);
		if (rect.containsPoint(locationInNode)){
			if(UserDefault::getInstance()->getIntegerForKey("backmusic",1) == 1)//0表示禁止BGM，1表示开启
				UserDefault::getInstance()->setIntegerForKey("backmusic",0);
			else
				UserDefault::getInstance()->setIntegerForKey("backmusic",1);
			target->setScale(1.1f);
			return true;
		}
		return false;
	};
	button_backMusic_listener->onTouchEnded = [&](Touch* touch, Event* event){//点击结束后，对音乐按钮图标和背景音乐进行相应处理
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		target->setScale(1.0f);
		if(UserDefault::getInstance()->getIntegerForKey("backmusic",1) == 1){//0表示禁止BGM，1表示开启
			SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
			target->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("options_overlay_buttons_0001.png"));
		}else{
			SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
			target->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("options_overlay_buttons_0002.png"));
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(button_backMusic_listener,backMusic);

	Sprite* backEffect;
	if(UserDefault::getInstance()->getIntegerForKey("backeffect",1) == 1)//0表示禁止BGM，1表示开启
		backEffect = Sprite::createWithSpriteFrameName("options_overlay_buttons_0003.png");
	else
		backEffect = Sprite::createWithSpriteFrameName("options_overlay_buttons_0004.png");
	backEffect->setPosition(Point(backMusic->getPosition().x + backMusic->getContentSize().width, winSize.height - backEffect->getContentSize().height / 2 - 10));
	addChild(backEffect);
	auto button_backEffect_listener = EventListenerTouchOneByOne::create();
	button_backEffect_listener->onTouchBegan = [&](Touch* touch, Event* event){
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		Point locationInNode = target->convertTouchToNodeSpace(touch);
		Size size = target->getContentSize();
		Rect rect = Rect(0, 0, size.width, size.height);
		if (rect.containsPoint(locationInNode)){
			if(UserDefault::getInstance()->getIntegerForKey("backeffect",1) == 1) //0表示禁止音效，1表示开启
				UserDefault::getInstance()->setIntegerForKey("backeffect",0);
			else
				UserDefault::getInstance()->setIntegerForKey("backeffect",1);
			target->setScale(1.1f);
			return true;
		}
		return false;
	};
	button_backEffect_listener->onTouchEnded = [&](Touch* touch, Event* event){
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		target->setScale(1.0f);
		if(UserDefault::getInstance()->getIntegerForKey("backeffect",1) == 1)//0表示禁止音效，1表示开启
			target->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("options_overlay_buttons_0003.png"));
		else
			target->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("options_overlay_buttons_0004.png"));
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(button_backEffect_listener,backEffect);
}

void WelcomeScene::initMenu_save(){
	menu_Save = Sprite::createWithSpriteFrameName("mainmenu_saveslot_bg.png");
	point_Menu_Save.x = point_Logo.x;
	point_Menu_Save.y = point_Logo.y - sprite_Logo->getContentSize().height * 1.4 / 2;

	menu_Save->setPosition(Point(point_Menu_Save.x,point_Menu_Save.y - 500));//起始在屏幕下500距离处，以方便移入

	//三个存档槽
	auto slot_0 = SlotMenu::createMenu(2);//中间
	slot_0->setPosition(Point(menu_Save->getContentSize().width / 2,menu_Save->getContentSize().height / 2));
	menu_Save->addChild(slot_0);
	auto slot_1 = SlotMenu::createMenu(1);//左
	slot_1->setPosition(Point(menu_Save->getContentSize().width / 4 - 30,menu_Save->getContentSize().height / 2));
	menu_Save->addChild(slot_1);
	auto slot_2 = SlotMenu::createMenu(3);//右
	slot_2->setPosition(Point(menu_Save->getContentSize().width / 4 * 3 + 30,menu_Save->getContentSize().height / 2));
	menu_Save->addChild(slot_2);

	addChild(menu_Save,0);

	button_Menu_Save_Close = MenuItemSprite::create(
		Sprite::createWithSpriteFrameName("mainmenu_saveslot_close_0001.png"),
		Sprite::createWithSpriteFrameName("mainmenu_saveslot_close_0002.png"),
		CC_CALLBACK_1(WelcomeScene::savemenuCloseCallback, this));
	point_Button_Menu_Save_Close.x = point_Logo.x;
	point_Button_Menu_Save_Close.y = point_Menu_Save.y - menu_Save->getContentSize().height / 2 + button_Menu_Save_Close->getContentSize().height + 2;
	button_Menu_Save_Close->setPosition(Point(point_Button_Menu_Save_Close.x,point_Button_Menu_Save_Close.y - 500));

	auto menu = Menu::create(button_Menu_Save_Close,NULL);
	menu->setPosition(Vec2::ZERO);
	addChild(menu,0);
}

void WelcomeScene::initLogoAnimation(){
	auto sprite = Sprite::createWithSpriteFrameName("logo_brillo_0001.png");
	sprite->setPosition(point_Logo);

	//生成闪光logo动画
	SpriteFrame* frame = NULL;
	Vector<SpriteFrame*> aFrames(20);
	for (int i = 1; i <= 21; i++){
		frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(__String::createWithFormat("logo_brillo_00%02d.png",i)->getCString());
		if(frame != nullptr) aFrames.pushBack(frame);
	}
	addChild(sprite,10);

	auto animation = Animation::createWithSpriteFrames(aFrames,0.1f);
	sprite->runAction(RepeatForever::create(Animate::create(animation)));
}

void WelcomeScene::initButton_startAnimation(){
	button_Start->setVisible(true);
	button_Start->runAction(MoveTo::create(0.3f, Point(point_Logo.x,point_Logo.y - 180)));
}

void WelcomeScene::init_creditBtn_startAnimation(){
	button_credit->runAction(Sequence::create(
		DelayTime::create(0.3f),
		CallFuncN::create(CC_CALLBACK_0(Sprite::setVisible, button_credit,true)),
		MoveTo::create(0.3f, Point(point_Logo.x,point_Logo.y - 360)),NULL));
}

void WelcomeScene::savemenuCloseCallback(cocos2d::Ref* pSender)
{
	SoundManager::playClickEffect();
	setSaveMenuInVisible();
	initButton_startAnimation();
	init_creditBtn_startAnimation();
}

void WelcomeScene::setSaveMenuInVisible(){
	//移出屏幕外
	menu_Save->runAction(MoveBy::create(0.3f,Point(0,-500)));
	button_Menu_Save_Close->runAction(MoveBy::create(0.3f,Point(0,-500)));
}

void WelcomeScene::setSaveMenuVisible(){
	//移到屏幕内
	menu_Save->runAction(MoveTo::create(0.3f,point_Menu_Save));
	button_Menu_Save_Close->runAction(MoveTo::create(0.3f,point_Button_Menu_Save_Close));
}

void WelcomeScene::onKeyReleased(EventKeyboard::KeyCode keycode, Event* event){
    switch (keycode){
	case EventKeyboard::KeyCode::KEY_BACK:   //返回键听
		if(button_Start->isVisible()){
			SimpleAudioEngine::getInstance()->end();
			Director::getInstance()->end();
			#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID ) exit(0);
			#endif
		}else{
			//在存档菜单层，则返回上一层
			setSaveMenuInVisible();
			initButton_startAnimation();
			init_creditBtn_startAnimation();
		}
        break;
    case EventKeyboard::KeyCode::KEY_MENU:      //菜单监听
        break;
    case::EventKeyboard::KeyCode::KEY_HOME:
        break;
    default:
        break;
    }
}