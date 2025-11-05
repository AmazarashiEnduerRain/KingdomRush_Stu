//
// Created by 20619 on 2025/11/5.
//

#ifndef KINGDOMRUSH_STU_WASPQUEEN_H
#define KINGDOMRUSH_STU_WASPQUEEN_H

#include "Monster/BaseMonster.h"
#include "cocos2d.h"
USING_NS_CC;

class WaspQueen : public BaseMonster{
public:
    virtual bool init() override;
    static WaspQueen* createMonster(std::vector<Point> points, int hp ,int value);
    static WaspQueen* createMonster(std::vector<Point> points);
    void refrozen(float dt) override;
    void frozen() override;
};


#endif //KINGDOMRUSH_STU_WASPQUEEN_H