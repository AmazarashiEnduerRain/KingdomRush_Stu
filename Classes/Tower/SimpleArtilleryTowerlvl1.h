//
// Created by 20619 on 2025/11/7.
//

#ifndef KINGDOMRUSH_STU_SIMPLEARTILLERYTOWERLVL1_H
#define KINGDOMRUSH_STU_SIMPLEARTILLERYTOWERLVL1_H

#include "cocos2d.h"
#include "BaseArtilleryTower.h"

USING_NS_CC;

class SimpleArtilleryTowerlvl1: public BaseArtilleryTower{
public:
    bool init() override;
    CREATE_FUNC(SimpleArtilleryTowerlvl1);
    void updateTower() override;
    void showUpdateMenu() override;

private:
    void buildingAnimation();
    void buildingSmokeAnimation(float dt);
};


#endif //KINGDOMRUSH_STU_SIMPLEARTILLERYTOWERLVL1_H