//
// Created by 20619 on 2025/11/20.
//
#include "EncyclopediaScene.h"
#include "EncyclopediaTips.h"
#include "EnemyScene.h"
#include "TowerScene.h"
#include "Data/SoundManager.h"
USING_NS_CC;

Scene* EncyclopediaScene::createScene(){
    auto scene = Scene::create();
    auto layer = EncyclopediaScene::create();
    scene->addChild(layer);
    return scene;
}

bool EncyclopediaScene::init(){
    if ( !Layer::init() ) return false;

	Size visibleSize = Director::getInstance()->getVisibleSize();

	for(int i = 0;i < 4;i++){
		for(int j = 0;j < 5;j++){
			auto sprite = Sprite::createWithSpriteFrameName("encyclopedia_bgTile.png");
			sprite->setPosition(Point(i * 310,j * 150));
			sprite->setAnchorPoint(Point(0,0));
			addChild(sprite);
		}
	}

	//防御塔百科按钮
    auto sprite11 = Sprite::createWithSpriteFrameName("encyclopedia_button_towers_0001.png");
	sprite11->setScale(0.95f);//选中时按下状态的按钮
	auto sprite1 = MenuItemSprite::create(
		Sprite::createWithSpriteFrameName("encyclopedia_button_towers_0001.png"),
		sprite11,
		CC_CALLBACK_1(EncyclopediaScene::menuNextCallback2,this));
    auto ccmenuu1 = Menu::create(sprite1,NULL);  //实现三者之间的顺序切换
    sprite1->setPosition(Point(visibleSize.width * 0.23,visibleSize.height * 0.65));
	ccmenuu1->setPosition(Vec2::ZERO);
    this->addChild(ccmenuu1,2);

	//敌人百科按钮
	auto sprite21 = Sprite::createWithSpriteFrameName("encyclopedia_button_enemies_0001.png");
	sprite21->setScale(0.95f);
	auto sprite2 = MenuItemSprite::create(
		Sprite::createWithSpriteFrameName("encyclopedia_button_enemies_0001.png"),
		sprite21,
		CC_CALLBACK_1(EncyclopediaScene::menuNextCallback3,this));
    auto ccmenuu2 = Menu::create(sprite2,NULL);
    sprite2->setPosition(Point(visibleSize.width * 0.57,visibleSize.height * 0.5));
	ccmenuu2->setPosition(Vec2::ZERO);
    this->addChild(ccmenuu2,2);

	//游戏提示按钮
	auto sprite31 = Sprite::createWithSpriteFrameName("encyclopedia_button_tips_0001.png");
	sprite31->setScale(0.8f);
	auto sprite32 = Sprite::createWithSpriteFrameName("encyclopedia_button_tips_0001.png");
	sprite32->setScale(0.75f);
	auto sprite3 = MenuItemSprite::create(
		sprite31,
		sprite32,
		CC_CALLBACK_1(EncyclopediaScene::menuNextCallback1,this));
    auto ccmenuu3 = Menu::create(sprite3,NULL);
    sprite3->setPosition(Point(visibleSize.width * 0.86,visibleSize.height * 0.3));
	ccmenuu3->setPosition(Vec2::ZERO);
    this->addChild(ccmenuu3,2);

	//攻略指南图标（装饰）
	auto sprite4 = Sprite::createWithSpriteFrameName("encyclopedia_button_strategyGuide_0001.png");
    sprite4->setPosition(Point(visibleSize.width * 0.22,visibleSize.height * 0.2));
	sprite4->setScale(0.9f);
    this->addChild(sprite4,1);

	auto sprite5 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("encyclopedia_button_close_0001.png"),
		Sprite::createWithSpriteFrameName("encyclopedia_button_close_0001.png"),
		CC_CALLBACK_1(EncyclopediaScene::menuNextCallback4,this));
    auto ccmenuu5 = Menu::create(sprite5,NULL);
    sprite5->setPosition(Point(visibleSize.width * 0.87,visibleSize.height * 0.83));
	ccmenuu5->setPosition(Vec2::ZERO);
    this->addChild(ccmenuu5,2);

	return true;
}

void EncyclopediaScene::menuNextCallback1(Ref *pSender ){
	SoundManager::playClickEffect();
    Director::getInstance()->pushScene(EncyclopediaTips::createScene());
}

void EncyclopediaScene::menuNextCallback2(Ref *pSender ){
	SoundManager::playClickEffect();
	Director::getInstance()->pushScene(TowerScene::createScene());
}

void EncyclopediaScene::menuNextCallback3(Ref *pSender ){
	SoundManager::playClickEffect();
	Director::getInstance()->pushScene(EnemyScene::createScene());
}

void EncyclopediaScene::menuNextCallback4(Ref *pSender ){
	SoundManager::playClickEffect();
	Director::getInstance()->popScene();
 }