//
// Created by 20619 on 2025/11/17.
//

#ifndef KINGDOMRUSH_STU_UPDATEPANLELAYERWITHFLAG_H
#define KINGDOMRUSH_STU_UPDATEPANLELAYERWITHFLAG_H

#include "cocos2d.h"
#include "Sprite/Circle/Circle.h"
#include "Tower/BaseBarracksTower.h"
#include "Sprite/TowerIcon/BaseBuildIcon.h"
#include "Sprite/TowerIcon/SellIcon.h"
USING_NS_CC;

class UpdatePanleLayerWithFlag: public Layer{
public:
    virtual bool init() override;
    CREATE_FUNC(UpdatePanleLayerWithFlag);
    void inAnimation();
    BaseBuildIcon* updateIcon;
    SellIcon* sellIcon;
    bool couldUpdate;
    Sprite* lock;
    Sprite* flag;
    CC_SYNTHESIZE(BaseBarracksTower*, tower, Tower);
private:
    void addIcons();
    void showTowerInfo();
    Sprite* planeSprite;
    bool onTouchBegan(Touch *touch, Event *event) override;
    void onTouchEnded(Touch* touch, Event* event) override;
    bool isActionTaken;
};
#endif //KINGDOMRUSH_STU_UPDATEPANLELAYERWITHFLAG_H