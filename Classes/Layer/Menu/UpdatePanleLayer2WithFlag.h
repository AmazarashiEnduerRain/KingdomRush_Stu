//
// Created by 20619 on 2025/11/17.
//

#ifndef KINGDOMRUSH_STU_UPDATEPANLELAYER2WITHFLAG_H
#define KINGDOMRUSH_STU_UPDATEPANLELAYER2WITHFLAG_H

#include "cocos2d.h"
#include "Sprite/Circle/Circle.h"
#include "Tower/BaseBarracksTower.h"
#include "Sprite/TowerIcon/BaseBuildIcon.h"
#include "Sprite/TowerIcon/SellIcon.h"
USING_NS_CC;

class UpdatePanleLayer2WithFlag: public Sprite{
public:
    virtual bool initWithIcons(int icon1,int icon2,int money1,int money2);
    static UpdatePanleLayer2WithFlag* createPanle(int icon1,int icon2,int money1,int money2);
    CREATE_FUNC(UpdatePanleLayer2WithFlag);
    void inAnimation();
    BaseBuildIcon* updateIcon1;
    BaseBuildIcon* updateIcon2;
    SellIcon* sellIcon;
    bool couldUpdate1;
    bool couldUpdate2;
    Sprite* lock1;
    Sprite* lock2;
    CC_SYNTHESIZE(BaseBarracksTower*, tower, Tower);
    Sprite* flag;
private:
    void addIcons();
    Sprite* planeSprite;
    bool onTouchBegan(Touch *touch, Event *event);
    void onTouchEnded(Touch* touch, Event* event);
    bool isActionTaken;
};

#endif //KINGDOMRUSH_STU_UPDATEPANLELAYER2WITHFLAG_H