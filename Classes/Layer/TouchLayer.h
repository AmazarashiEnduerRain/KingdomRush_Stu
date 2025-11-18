//
// Created by 20619 on 2025/11/18.
// 游戏交互层，处理各种点击

#ifndef KINGDOMRUSH_STU_TOUCHLAYER_H
#define KINGDOMRUSH_STU_TOUCHLAYER_H

#include "cocos2d.h"
#include "Tower/BaseTower.h"
#include "Sprite/Circle/RallyCircle.h"
USING_NS_CC;

class TouchLayer :public Layer{
public:
    bool init() override;
    CREATE_FUNC(TouchLayer);
    //各种事件的监听器
    EventListenerTouchOneByOne* listener;//设置集结点
    EventListenerTouchOneByOne* touchlistener;//普通触摸（地图拖动，点击防御塔等）
    EventListenerTouchOneByOne* Soldierlistener;//援兵事件
    EventListenerTouchOneByOne* Freezelistener;//冰冻道具
    EventListenerTouchOneByOne* Dynamitelistener;//炸弹道具
    EventListenerTouchOneByOne* FiereBalllistener;//陨石事件
    //设置/移除特定事件的遮蔽
    void setDynamiteTouchShield();
    void removeDynamiteTouchShield();
    bool onDynamiteTouchBegan(Touch* touch, Event* event);
    void onDynamiteTouchEnded(Touch* touch, Event* event);

    void setRallyFlagTouchShield();
    void removeRallyFlagTouchShield();
    bool onRallyFlagTouchBegan(Touch* touch, Event* event);
    void onRallyFlagTouchEnded(Touch* touch, Event* event);

    void setSoldierTouchShield();
    void removeSoldierTouchShield();
    bool onSoldierTouchBegan(Touch* touch, Event* event);
    void onSoldierTouchEnded(Touch* touch, Event* event);

    void setFreezeTouchShield();
    void removeFreezeTouchShield();
    bool onFreezeTouchBegan(Touch* touch, Event* event);
    void onFreezeTouchEnded(Touch* touch, Event* event);

    void setFireBallTouchShield();
    void removeFireBallTouchShield();
    bool onFireBallTouchBegan(Touch* touch, Event* event);
    void onFireBallTouchEnded(Touch* touch, Event* event);

    void removeTouchShield();
    void setTouchShield();

    BaseTower* tower;//当前选中塔
    RallyCircle* rallyCircle;//集结点范围显示
    void addRallyFlag(Point location);//显示集结旗帜动画
    void addWrongPlace(Point location);//显示错误动画（即点击在无法集结处）

    //触摸回调
    bool onTouchBegan(Touch* touch, Event* event) override;
    void onTouchEnded(Touch* touch, Event* event) override;
    void onTouchMoved(Touch* touch, Event* event) override;

    Size winSize;
    bool isMoved;//标记是否发生拖动。如果拖动，不视为点击
    bool isFlag;

    void removeAllListener();
};

#endif //KINGDOMRUSH_STU_TOUCHLAYER_H