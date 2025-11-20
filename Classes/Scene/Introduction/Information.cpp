//
// Created by 20619 on 2025/11/20.
//

#include "Information.h"
#include "Scene/WelcomeScene.h"
USING_NS_CC;

Scene *Information::createScene() {
    auto scene = Scene::create();
    auto layer = Information::create();
    scene->addChild(layer);
    return scene;
}

bool Information::init() {
    if (!Layer::init()) return false;
    initMap();

    return true;
}


void Information::initMap() {
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("credits_scene-hd.plist");

    Size size = Director::getInstance()->getVisibleSize();

    //顶部卷轴背景
    auto tileTopSprite = Sprite::createWithSpriteFrameName("credits_tileTop.png");
    tileTopSprite->setPosition(size.width * 0.5, size.height * 0.6);
    tileTopSprite->setScaleX(0.5);
    addChild(tileTopSprite, 0);

    //背景
    auto tileSprite = Sprite::createWithSpriteFrameName("credits_tile.png");
    tileSprite->setPosition(size.width * 0.5, size.height * 0.3);
    tileSprite->setScaleX(0.5);
    addChild(tileSprite, 0);

    //左上角的剑
    auto swordSprite = Sprite::createWithSpriteFrameName("credits_sword.png");
    swordSprite->setPosition(size.width * 0.9, size.height * 0.8);
    swordSprite->setScale(0.5);
    addChild(swordSprite, 1);

    //返回按钮
    auto sprite1 = Sprite::createWithSpriteFrameName("credits_back_0001.png");
    sprite1->setScale(0.5);
    auto sprite2 = Sprite::createWithSpriteFrameName("credits_back_0002.png");
    sprite2->setScale(0.5);
    auto item = MenuItemSprite::create(sprite1, sprite2, CC_CALLBACK_1(Information::callBackMenu, this));
    item->setPosition(Point(size.width * 0.2, size.height * 0.25));
    Menu *menu1 = Menu::create(item, NULL);
    menu1->setPosition(Vec2::ZERO);
    this->addChild(menu1, 1);


    auto label = Label::createWithTTF("Kingdom Rush Stu", "SohoGothicProMedium.ttf", 36);
    label->setPosition(Point(size.width * 0.5, size.height * 0.75));
    label->setColor(Color3B::BLACK);
    addChild(label, 1);

    auto label0 = Label::createWithTTF("by C3 ", "SohoGothicProMedium.ttf", 28);
    label0->setPosition(Point(size.width * 0.7, size.height * 0.7));
    label0->setColor(Color3B::BLACK);
    addChild(label0, 1);

    auto label1 = Label::createWithTTF("Developed by Amazarashi:", "SohoGothicProMedium.ttf", 26);
    label1->setPosition(Point(size.width * 0.5, size.height * 0.6));
    label1->setColor(Color3B::BLACK);
    addChild(label1, 1);

    auto label2 = Label::createWithTTF("Thanks for resources provided by:", "SohoGothicProMedium.ttf", 26);
    label2->setPosition(Point(size.width * 0.5, size.height * 0.5));
    label2->setColor(Color3B::BLACK);
    addChild(label2, 1);

    auto label3 = Label::createWithTTF("Wu Hao Yu, Zhang Jun Jie, Zhang Lei, Zhang Qing", "SohoGothicProMedium.ttf", 26);
    label3->setPosition(Point(size.width * 0.5, size.height * 0.4));
    label3->setColor(Color3B::BLACK);
    addChild(label3, 1);
}

void Information::callBackMenu(Ref *pSpender) {
    Director::getInstance()->replaceScene(WelcomeScene::createScene());//返回欢迎界面
}
