//
// Created by 20619 on 2025/11/9.
//

#ifndef KINGDOMRUSH_STU_DEATHKNIGHT_H
#define KINGDOMRUSH_STU_DEATHKNIGHT_H

#include "BaseSoldier.h"
class DeathKnight : public BaseSoldier{
public:
    bool init() override;
    CREATE_FUNC(DeathKnight);
    static DeathKnight* createDeathKnight(Point point);
    void update(float dt) override;
    void attackMonster(float dt) override;
    void birth(Point point);
    void createAndSetHpBar() override;
};

#endif //KINGDOMRUSH_STU_DEATHKNIGHT_H