//
// Created by 20619 on 2025/11/3.
//

#ifndef KINGDOMRUSH_STU_THUG_H
#define KINGDOMRUSH_STU_THUG_H

#include "Monster/BaseMonster.h"
#include "cocos2d.h"
USING_NS_CC;

class Thug : public BaseMonster{
public:
    virtual bool init() override;
    static Thug* createMonster(std::vector<Point> points, int hp ,int value);
    static Thug* createMonster(std::vector<Point> points);
};


#endif //KINGDOMRUSH_STU_THUG_H