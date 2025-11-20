//
// Created by 20619 on 2025/11/3.
//

#ifndef KINGDOMRUSH_STU_WOLF_H
#define KINGDOMRUSH_STU_WOLF_H

#include "Monster/BaseMonster.h"
#include "cocos2d.h"

USING_NS_CC;

class Wolf : public BaseMonster{
public:
    virtual bool init() override;//重写init方法，用于设置wolf特定的精灵和属性
    static Wolf* createMonster(std::vector<Point> points, int hp ,int value);
    static Wolf* createMonster(std::vector<Point> points);
};


#endif //KINGDOMRUSH_STU_WOLF_H