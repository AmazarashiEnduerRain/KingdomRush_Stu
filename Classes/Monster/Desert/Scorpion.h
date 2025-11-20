//
// Created by 20619 on 2025/11/3.
//

#ifndef KINGDOMRUSH_STU_SCORPION_H
#define KINGDOMRUSH_STU_SCORPION_H

#include "Monster/BaseMonster.h"
#include "cocos2d.h"

USING_NS_CC;

class Scorpion : public BaseMonster{
public:
    virtual bool init() override;
    static Scorpion* createMonster(std::vector<Point> points);
};


#endif //KINGDOMRUSH_STU_SCORPION_H