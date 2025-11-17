//
// Created by 20619 on 2025/11/5.
//

#ifndef KINGDOMRUSH_STU_REINFORCESOLDIER2_H
#define KINGDOMRUSH_STU_REINFORCESOLDIER2_H

#include "BaseSoldier.h"

class ReinforceSoldier2 : public BaseSoldier{
public:
    bool init() override;
    CREATE_FUNC(ReinforceSoldier2);
    static ReinforceSoldier2* createReinforceSoldier(Point point);
    void update(float dt) override;
    void attackMonster(float dt) override;

    void birth(Point point);

    void checkNearestMonster() override;
    bool checkDirectionForMonster() override;
    void runToMonster() override;
};

#endif //KINGDOMRUSH_STU_REINFORCESOLDIER2_H