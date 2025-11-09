//
// Created by 20619 on 2025/11/9.
//

#ifndef KINGDOMRUSH_STU_TEMPLAR_H
#define KINGDOMRUSH_STU_TEMPLAR_H

#include "BaseSoldier.h"

class Templar : public BaseSoldier{
public:
    bool initTemplar();
    CREATE_FUNC(Templar);
    static Templar* createTemplar(Point location);
    void createAndSetHpBar() override;
    void checkState();
    void update(float dt) override;
    void attackMonster(float dt) override;
};


#endif //KINGDOMRUSH_STU_TEMPLAR_H