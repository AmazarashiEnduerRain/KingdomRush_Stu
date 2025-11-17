//
// Created by 20619 on 2025/11/9.
//

#ifndef KINGDOMRUSH_STU_ASSASSIN_H
#define KINGDOMRUSH_STU_ASSASSIN_H

#include "BaseSoldier.h"
class Assassin : public BaseSoldier{
public:
    bool initAssassin();
    CREATE_FUNC(Assassin);
    static Assassin* createAssassin(Point location);
    void createAndSetHpBar() override;
    void checkState();
    void update(float dt) override;
    void attackMonster(float dt) override;
};


#endif //KINGDOMRUSH_STU_ASSASSIN_H