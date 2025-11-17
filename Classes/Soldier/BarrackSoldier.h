//
// Created by 20619 on 2025/11/5.
//

#ifndef KINGDOMRUSH_STU_BARRACKSOLDIER_H
#define KINGDOMRUSH_STU_BARRACKSOLDIER_H

#include "BaseSoldier.h"

class BarrackSoldier : public BaseSoldier{
public:
    bool initSoldier(int level);
    CREATE_FUNC(BarrackSoldier);
    static BarrackSoldier* createSoldier(Point point,int level);
    CC_SYNTHESIZE(int, level, Level);
    void update(float dt) override;
    void attackMonster(float dt) override;
    void updateSoldier(int level) override;
};


#endif //KINGDOMRUSH_STU_BARRACKSOLDIER_H