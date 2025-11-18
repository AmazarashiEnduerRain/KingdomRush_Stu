//
// Created by 20619 on 2025/11/17.
// 简化的塔操作面板，仅有出售按钮

#ifndef KINGDOMRUSH_STU_SIMPLEPANLELAYER_H
#define KINGDOMRUSH_STU_SIMPLEPANLELAYER_H

#include "cocos2d.h"
#include "Sprite/Circle/Circle.h"
#include "Tower/BaseTower.h"
#include "Sprite/TowerIcon/SellIcon.h"
USING_NS_CC;

class SimplePanleLayer: public Layer{
public:
    virtual bool init() override;
    CREATE_FUNC(SimplePanleLayer);
    void inAnimation();
    SellIcon* sellIcon;//指向出售图标
    CC_SYNTHESIZE(BaseTower*, tower, Tower);//存储当前面板所属的防御塔类别
private:
    void addIcons();
    Sprite* planeSprite;//菜单的背景
    Circle* thisLvlCircle;//射程圈
    bool onTouchBegan(Touch *touch, Event *event);
    void onTouchEnded(Touch* touch, Event* event);
    bool isActionTaken;//表示是否执行了操作。如果出售，将移除面板
};


#endif //KINGDOMRUSH_STU_SIMPLEPANLELAYER_H