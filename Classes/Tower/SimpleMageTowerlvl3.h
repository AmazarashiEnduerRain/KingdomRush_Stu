//
// Created by 20619 on 2025/11/7.
//

#ifndef KINGDOMRUSH_STU_SIMPLEMAGETOWERLVL3_H
#define KINGDOMRUSH_STU_SIMPLEMAGETOWERLVL3_H

#include "cocos2d.h"
#include "BaseMageTower.h"
USING_NS_CC;

class SimpleMageTowerlvl3: public BaseMageTower{
public:
    bool init() override;
    CREATE_FUNC(SimpleMageTowerlvl3);
    void updateTower() override;
    void showUpdateMenu() override;
    Bullet* MageTowerBullet() override;
    void update1() override;
    void update2() override;
};


#endif //KINGDOMRUSH_STU_SIMPLEMAGETOWERLVL3_H