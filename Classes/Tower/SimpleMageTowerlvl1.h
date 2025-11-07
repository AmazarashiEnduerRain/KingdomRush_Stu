//
// Created by 20619 on 2025/11/7.
//

#ifndef KINGDOMRUSH_STU_SIMPLEMAGETOWERLVL1_H
#define KINGDOMRUSH_STU_SIMPLEMAGETOWERLVL1_H
#include "cocos2d.h"
#include "BaseMageTower.h"

USING_NS_CC;

class SimpleMageTowerlvl1: public BaseMageTower{
public:
    bool init() override;
    CREATE_FUNC(SimpleMageTowerlvl1);
    void updateTower() override;
    void showUpdateMenu() override;
    Bullet* MageTowerBullet() override;
private:
    void buildingAnimation();
    void buildingSmokeAnimation(float dt);
};


#endif //KINGDOMRUSH_STU_SIMPLEMAGETOWERLVL1_H