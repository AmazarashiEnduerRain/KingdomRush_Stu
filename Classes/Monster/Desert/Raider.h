//
// Created by 20619 on 2025/11/3.
//

#ifndef KINGDOMRUSH_STU_RAIDER_H
#define KINGDOMRUSH_STU_RAIDER_H

#include "Monster/BaseMonster.h"
#include "cocos2d.h"

USING_NS_CC;

class Raider : public BaseMonster{
public:
    virtual bool init() override;
    static Raider* createMonster(std::vector<Point> points);
};



#endif //KINGDOMRUSH_STU_RAIDER_H