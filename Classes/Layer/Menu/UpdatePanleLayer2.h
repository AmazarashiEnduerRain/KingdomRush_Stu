//
// Created by 20619 on 2025/11/17.
//

#ifndef KINGDOMRUSH_STU_UPDATEPANLELAYER2_H
#define KINGDOMRUSH_STU_UPDATEPANLELAYER2_H

#include "cocos2d.h"
#include "Sprite/Circle/Circle.h"
#include "Tower/BaseTower.h"
#include "Sprite/TowerIcon/BaseBuildIcon.h"
#include "Sprite/TowerIcon/SellIcon.h"
USING_NS_CC;

class UpdatePanleLayer2: public Sprite{
public:
    virtual bool initWithIcons(int icon1,int icon2,int money1,int money2);
    static UpdatePanleLayer2* createPanle(int icon1,int icon2,int money1,int money2);
    CREATE_FUNC(UpdatePanleLayer2);
    void inAnimation();
    //高级塔的升级面板。其具有左右两个图标
    BaseBuildIcon* updateIcon1;
    BaseBuildIcon* updateIcon2;
    SellIcon* sellIcon;
    bool couldUpdate1;
    bool couldUpdate2;
    Sprite* lock1;
    Sprite* lock2;
    Circle* thisLvlCircle;
    Circle* nextLvlCircle;
    CC_SYNTHESIZE(BaseTower*, tower, Tower);
private:
    void addIcons();
    Sprite* planeSprite;
    void showTowerInfo_1();
    void showTowerInfo_2();
    bool onTouchBegan(Touch *touch, Event *event);
    void onTouchEnded(Touch* touch, Event* event);
    bool isActionTaken;
};

#endif //KINGDOMRUSH_STU_UPDATEPANLELAYER2_H