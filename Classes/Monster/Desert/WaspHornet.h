//
// Created by 20619 on 2025/11/5.
// 胡蜂：飞行单位，重写frozen逻辑（不适用默认的地面单位冰冻逻辑）

#ifndef KINGDOMRUSH_STU_WASPHORNET_H
#define KINGDOMRUSH_STU_WASPHORNET_H


#include "Monster/BaseMonster.h"
#include "cocos2d.h"
USING_NS_CC;

class WaspHornet : public BaseMonster{
public:
    virtual bool init() override;
    static WaspHornet* createMonster(std::vector<Point> points, int hp ,int value);
    static WaspHornet* createMonster(std::vector<Point> points);
    void frozen() override;
    void refrozen(float dt) override;
};


#endif //KINGDOMRUSH_STU_WASPHORNET_H