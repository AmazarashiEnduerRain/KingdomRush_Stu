//
// Created by 20619 on 2025/11/7.
//

#ifndef KINGDOMRUSH_STU_SIMPLEMAGETOWERLVL2_H
#define KINGDOMRUSH_STU_SIMPLEMAGETOWERLVL2_H

#include "cocos2d.h"
#include "BaseMageTower.h"

USING_NS_CC;

class SimpleMageTowerlvl2: public BaseMageTower{
public:
    bool init() override;
    CREATE_FUNC(SimpleMageTowerlvl2);
    void updateTower() override;
    void showUpdateMenu() override;
    Bullet* MageTowerBullet() override;
};

#endif //KINGDOMRUSH_STU_SIMPLEMAGETOWERLVL2_H