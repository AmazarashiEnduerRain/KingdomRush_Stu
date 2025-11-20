//
// Created by 20619 on 2025/11/20.
// 防御塔图鉴界面

#ifndef KINGDOMRUSH_STU_TOWERSCENE_H
#define KINGDOMRUSH_STU_TOWERSCENE_H

#include "cocos2d.h"
#include "TowerDesc.h"
#include "EncyclopediaScene.h"
USING_NS_CC;

class Tower : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    bool init() override;
    void closeScene(Ref* pSendser);

    bool onTouchBegan(Touch* touch, Event* event) override;
    void onTouchEnded(Touch* touch, Event* event) override;

    CREATE_FUNC(Tower);
private:
    int towerId;
    MenuItemSprite* spriteCloseButton;

    Label* labelName;
    //3个属性
    Label* labelAttackSpeed;
    Label* labelAttackValue;
    Label* labelAttackRange;

    Label* labelNotice;

    //3个值
    Label* labelAttackSpeed1;
    Label* labelAttackValue1;
    Label* labelAttackRange1;

    Label* labelNotice1;

    Sprite* selectionFrame;//选中框
    MoveTo* moveFrame;//选中框移动的动画
    Size visibleSize;
    Sprite* bigSprite;

    TowerDesc* towerDesc[50];
};

#endif //KINGDOMRUSH_STU_TOWERSCENE_H