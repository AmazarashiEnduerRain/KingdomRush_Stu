//
// Created by 20619 on 2025/11/7.
//

#ifndef KINGDOMRUSH_STU_SIMPLEARROWTOWERLVL2_H
#define KINGDOMRUSH_STU_SIMPLEARROWTOWERLVL2_H

#include "cocos2d.h"
#include "BaseArrowTower.h"

USING_NS_CC;

class SimpleArrowTowerlvl2: public BaseArrowTower{
public:
    bool init() override;
    CREATE_FUNC(SimpleArrowTowerlvl2);
    void updateTower() override;
    void showUpdateMenu() override;
    Bullet* ArrowTowerBullet() override;
};


#endif //KINGDOMRUSH_STU_SIMPLEARROWTOWERLVL2_H