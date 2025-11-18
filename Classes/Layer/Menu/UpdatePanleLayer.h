//
// Created by 20619 on 2025/11/17.
//

#ifndef KINGDOMRUSH_STU_UPDATEPANLELAYER_H
#define KINGDOMRUSH_STU_UPDATEPANLELAYER_H

#include "cocos2d.h"
#include "Sprite/Circle/Circle.h"
#include "Tower/BaseTower.h"
#include "Sprite/TowerIcon/BaseBuildIcon.h"
#include "Sprite/TowerIcon/SellIcon.h"
USING_NS_CC;

class UpdatePanleLayer: public Sprite{
public:
    virtual bool init() override;
    CREATE_FUNC(UpdatePanleLayer);
    void inAnimation();
    BaseBuildIcon* updateIcon;
    SellIcon* sellIcon;
    bool couldUpdate;//控制是否能够升级。如果不能，显示锁的图标
    Sprite* lock;//锁的视觉精灵
    CC_SYNTHESIZE(BaseTower*, tower, Tower);
private:
    void addIcons();
    Sprite* planeSprite;
    Circle* thisLvlCircle;//当前等级范围
    Circle* nextLvlCircle;//下一等级的预览范围
    bool onTouchBegan(Touch *touch, Event *event);
    void onTouchEnded(Touch* touch, Event* event);
    bool isActionTaken;
    void showTowerInfo();//下一等级塔的预览信息
};

#endif //KINGDOMRUSH_STU_UPDATEPANLELAYER_H