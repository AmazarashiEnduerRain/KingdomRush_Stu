//
// Created by 20619 on 2025/11/7.
//

#ifndef KINGDOMRUSH_STU_SIMPLEARROWTOWERLVL3_H
#define KINGDOMRUSH_STU_SIMPLEARROWTOWERLVL3_H

#include "cocos2d.h"
#include "BaseArrowTower.h"
USING_NS_CC;
class SimpleArrowTowerlvl3: public BaseArrowTower{
public:
    bool init() override;
    CREATE_FUNC(SimpleArrowTowerlvl3);
    void updateTower() override;//对三级塔来说，不再能够线性升级，转而拥有两个高级升级选项
    void showUpdateMenu() override;
    Bullet* ArrowTowerBullet() override;
    void update1() override;
    void update2() override;
};


#endif //KINGDOMRUSH_STU_SIMPLEARROWTOWERLVL3_H