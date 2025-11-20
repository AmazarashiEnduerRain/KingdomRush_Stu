//
// Created by 20619 on 2025/11/20.
//
#include "cocos2d.h"
#include "EncyclopediaTips.h"
#include "EncyclopediaScene.h"
#include "Data/SoundManager.h"
USING_NS_CC;

Scene *EncyclopediaTips::createScene() {
    auto scene = Scene::create();
    auto layer = EncyclopediaTips::create();
    scene->addChild(layer);
    return scene;
}

bool EncyclopediaTips::init() {
    if (!Layer::init()) return false;

    Size visibleSize = Director::getInstance()->getVisibleSize();
    currentIdx = 1;

    //背景平铺
    for (int h = 0; h < 4; h++) {
        for (int k = 0; k < 5; k++) {
            auto sprite = Sprite::createWithSpriteFrameName("encyclopedia_bgTile.png");
            sprite->setPosition(Point(h * 310, k * 150));
            sprite->setAnchorPoint(Point(0, 0));
            addChild(sprite);
        }
    }

    //书页背景拼凑
    auto bgLeft = Sprite::createWithSpriteFrameName("encyclopedia_tips_left.png");
    bgLeft->setPosition(Point(visibleSize.width * 0.21, visibleSize.height * 0.5));
    this->addChild(bgLeft, 1);
    auto bgMiddle = Sprite::createWithSpriteFrameName("encyclopedia_tips_middle.png");
    bgMiddle->setPosition(Point(visibleSize.width * 0.50, visibleSize.height * 0.5));
    bgMiddle->setScaleX(13.0f);
    this->addChild(bgMiddle, 1);
    auto bgRight = Sprite::createWithSpriteFrameName("encyclopedia_tips_left.png");
    bgRight->setPosition(Point(visibleSize.width * 0.79, visibleSize.height * 0.5));
    bgRight->setFlippedX(true);
    bgRight->setRotation(360);
    this->addChild(bgRight, 1);

    //关闭按钮
    auto closeBtn = MenuItemSprite::create(
        Sprite::createWithSpriteFrameName("LevelSelect_Back_0001.png"),
        Sprite::createWithSpriteFrameName("LevelSelect_Back_0002.png"),
        CC_CALLBACK_1(EncyclopediaTips::menuCallback, this));
    auto ccmenuu = Menu::create(closeBtn, NULL);
    closeBtn->setPosition(Point(visibleSize.width * 0.8, visibleSize.height * 0.81));
    ccmenuu->setPosition(Vec2::ZERO);
    this->addChild(ccmenuu, 2);

    //翻页按钮
    auto arrowNormal = Sprite::createWithSpriteFrameName("encyclopedia_tow_creep_arrow_0003.png");
    auto arrowPressed = Sprite::createWithSpriteFrameName("encyclopedia_tow_creep_arrow_0002.png");
    auto arrowDisabled = Sprite::createWithSpriteFrameName("encyclopedia_tow_creep_arrow_0001.png");

    auto leftNormal = Sprite::createWithSpriteFrameName("encyclopedia_tow_creep_arrow_0003.png");
    leftNormal->setFlippedX(true);
    leftNormal->setRotation(360);
    auto leftPressed = Sprite::createWithSpriteFrameName("encyclopedia_tow_creep_arrow_0002.png");
    leftPressed->setFlippedX(true);
    leftPressed->setRotation(360);
    auto leftDisabled = Sprite::createWithSpriteFrameName("encyclopedia_tow_creep_arrow_0001.png");
    leftDisabled->setFlippedX(true);
    leftDisabled->setRotation(360);

    leftDisabled->cleanup();
    btnLeft = MenuItemSprite::create(
        leftNormal, leftPressed, leftDisabled,
        CC_CALLBACK_1(EncyclopediaTips::starMenuCallback2, this));
    btnLeft->setPosition(Point(visibleSize.width * 0.4, visibleSize.height * 0.3));
    auto ccmenuu1 = Menu::create(btnLeft, NULL);
    ccmenuu1->setPosition(Vec2::ZERO);
    this->addChild(ccmenuu1, 2);
    btnLeft->setEnabled(false);//初始时在第一页

    btnRight = MenuItemSprite::create(
        arrowNormal, arrowPressed, arrowDisabled,
        CC_CALLBACK_1(EncyclopediaTips::starMenuCallback1, this));
    btnRight->setPosition(Point(visibleSize.width * 0.6, visibleSize.height * 0.3));
    auto ccmenuu2 = Menu::create(btnRight, NULL);
    ccmenuu2->setPosition(Vec2::ZERO);
    this->addChild(ccmenuu2, 2);

    //文本内容初始化
    tipsString[0] = "  Enemies and soldiers with armor  \n        receive less physical damage.";
    tipsString[1] =
            "    Support barracks with ranged  \n        rowers to maximize enemy     \n                     exposure.";
    tipsString[2] = " Reinforcements are a great way  \n          to split enemy forces.";
    tipsString[3] = "    Artillery works best against   \n   high concentration of enemies.";
    tipsString[4] = "  Artillery damage is highest in the\n         center of the explosion.";
    tipsString[5] = " Use reinforcements constantly\n    to slow and damage the enemy.";
    tipsString[6] = "     Always aim rain of fire a little\n           ahead of your target.";
    tipsString[7] = "     Rearranging your upgrade \n    point is a good way to adapt \n              your  strategy.";
    tipsString[8] = " Magic damage is the best way to\n      deal with armored enemies.";
    tipsString[9] =
            "  Flying enemies cannot be blocked\nby barrack and won't be targeted by\n                 most artillery.";
    tipsString[10] =
            "   Enemies with magic resistance \n    receive less damage from magic \n                      attacks.";
    tipsString[11] =
            "         Adjust the rally point of\n          soldiers to create better \n                    strategies.";
    tipsString[12] =
            "   Sometimes it is better to build\n         more towers instead of\n              upgrading a few.";
    tipsString[13] = "       Pestilence damage ignores \n                        armor.";
    tipsString[14] = " Upgrading a barrack instantly\n             trains new soldiers.";
    tipsString[15] =
            "       Calling an early wave gives\n      bonus cash and reduces spell\n                 cooldowns a bit.";
    tipsString[16] = " Artillery explosions can damage\n  flying enemies even though they\n   cannot target them directly.";
    tipsString[17] = "Use barracks or reinforcements \n   to isolate troublesome enemies.";
    tipsString[18] =
            "  Effects that kill instantly are a\n     great way to deal with tough \n                      enemies.";
    tipsString[19] =
            "   Keep your eye out for enemies\n   that trouble your defenses.More \n                 may come soon.";
    tipsString[20] =
            " You can check what enemies are\n   in the incoming wave by tapping\n             the wave icon once.";
    tipsString[21] =
            "         Dont be afraid of selling a\n        tower and replacing it with a \n              more suitable one.";
    tipsString[22] = "   Heroes and soldiers heal when\n                 they are idle.";
    tipsString[23] = "  Calling a wave earlier doesn't\n reduce cooldown of tower abilities.";
    tipsString[24] = " Sometimes it is wise to save some\n   gold to adapt to unexpected\n                    enemies.";
    tipsString[25] =
            "     Savages heal themselves and \n   become stronger every time they\n                           eat.";
    tipsString[26] = " Sand wraiths can't raise coffins\n                 while blocked.";
    tipsString[27] =
            "       Poison from enemies is not\n     lethal.Retreat your poisoned\n            soldiers to save them.";
    tipsString[28] = "the executioner cannot execute\n                        heroes.";
    tipsString[29] = "      Combined shaman auras can\n     make savages nearly invincible.";

    //标签
    pagNumLabel = Label::createWithTTF("1", "arial.ttf", 24);
    pagNumLabel->setPosition(Point(visibleSize.width * 0.47, visibleSize.height * 0.30));
    pagNumLabel->setColor(Color3B(0, 0, 0));
    addChild(pagNumLabel, 2);

    contentLabel = Label::createWithTTF(tipsString[0], "arial.ttf", 26);
    contentLabel->setPosition(Point(visibleSize.width * 0.55, visibleSize.height * 0.4));
    contentLabel->setColor(Color3B(0, 0, 0));
    contentLabel->setLineBreakWithoutSpace(true); //来支持自动换行功能
    contentLabel->setDimensions(visibleSize.width * 0.55, visibleSize.height * 0.4); //来控制自动换行
    this->addChild(contentLabel, 2);

    //固定文字
    auto label1 = Label::createWithTTF("/30", "arial.ttf", 24);
    label1->setPosition(Point(visibleSize.width * 0.50, visibleSize.height * 0.30));
    label1->setColor(Color3B(0, 0, 0));
    this->addChild(label1, 2);

    //标题“TIPS”
    auto label4 = Label::createWithTTF("TIPS", "arial.ttf", 36);
    label4->setPosition(Point(visibleSize.width * 0.5, visibleSize.height * 0.7));
    label4->setColor(Color3B(87, 0, 17));
    this->addChild(label4, 2);

    return true;
}

//关闭按钮，返回前一次的场景
void EncyclopediaTips::menuCallback(Ref *pSender) {
    SoundManager::playClickEffect();
    Director::getInstance()->popScene();
}

void EncyclopediaTips::starMenuCallback1(Ref *pSender) {
    SoundManager::playClickEffect();
    if (currentIdx < 31 && currentIdx > 0) {
        currentIdx++;
        if (currentIdx == 1) {
            btnLeft->setEnabled(false);
            btnRight->setEnabled(true);
        } else if (currentIdx == 30) {
            btnLeft->setEnabled(true);
            btnRight->setEnabled(false);
        } else {
            btnLeft->setEnabled(true);
            btnRight->setEnabled(true);
        }

        //显示数字变化
        pagNumLabel->setString(__String::createWithFormat("%d", currentIdx)->getCString());
        //显示内容变化
        contentLabel->setString(string[currentIdx - 1]);
    }
}

void EncyclopediaTips::starMenuCallback2(Ref *pSender) {
    SoundManager::playClickEffect();
    if (currentIdx < 31 && currentIdx > 0) {
        currentIdx--;
        if (currentIdx == 1) {
            btnLeft->setEnabled(false);
            btnRight->setEnabled(true);
        } else if (currentIdx == 30) {
            btnLeft->setEnabled(false);
            btnRight->setEnabled(true);
        } else {
            btnLeft->setEnabled(true);
            btnRight->setEnabled(true);
        }

        pagNumLabel->setString(__String::createWithFormat("%d", currentIdx)->getCString());
        contentLabel->setString(string[currentIdx - 1]);
    }
}