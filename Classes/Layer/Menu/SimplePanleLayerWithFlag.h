//
// Created by 20619 on 2025/11/17.
//

#ifndef KINGDOMRUSH_STU_SIMPLEPANLELAYERWITHFLAG_H
#define KINGDOMRUSH_STU_SIMPLEPANLELAYERWITHFLAG_H

#include "cocos2d.h"
#include "Sprite/Circle/Circle.h"
#include "Tower/BaseTower.h"
#include "Sprite/TowerIcon/SellIcon.h"
USING_NS_CC;

class SimplePanleLayerWithFlag: public Layer{
public:
    virtual bool init() override;
    CREATE_FUNC(SimplePanleLayerWithFlag);
    void inAnimation();
    SellIcon* sellIcon;
    Sprite* flag;//旗帜图标，用于设置集结点
    CC_SYNTHESIZE(BaseTower*, tower, Tower);
private:
    void addIcons();
    bool isActionTaken;
    Sprite* planeSprite;
    bool onTouchBegan(Touch *touch, Event *event) override;
    void onTouchEnded(Touch* touch, Event* event) override;
};


#endif //KINGDOMRUSH_STU_SIMPLEPANLELAYERWITHFLAG_H