//
// Created by 20619 on 2025/11/7.
//

#ifndef KINGDOMRUSH_STU_SIMPLEARROWTOWERLVL1_H
#define KINGDOMRUSH_STU_SIMPLEARROWTOWERLVL1_H

#include "cocos2d.h"
#include "BaseArrowTower.h"

USING_NS_CC;

class SimpleArrowTowerlvl1: public BaseArrowTower{
public:
    bool init() override;
    CREATE_FUNC(SimpleArrowTowerlvl1);
    void updateTower() override;
    void showUpdateMenu() override;
    Bullet* ArrowTowerBullet() override;
private:
    void buildingAnimation();
    void buildingSmokeAnimation(float dt);
};


#endif //KINGDOMRUSH_STU_SIMPLEARROWTOWERLVL1_H