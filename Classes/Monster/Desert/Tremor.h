//
// Created by 20619 on 2025/11/5.
// 沙虫：具有钻地与出地两种状态

#ifndef KINGDOMRUSH_STU_TREMOR_H
#define KINGDOMRUSH_STU_TREMOR_H

#include "Monster/BaseMonster.h"
#include "cocos2d.h"
USING_NS_CC;

class Tremor : public BaseMonster{
public:
    virtual bool init() override;
    static Tremor* createMonster(std::vector<Point> points, int hp ,int value);
    static Tremor* createMonster(std::vector<Point> points);
    void update(float dt) override;
    void stopWalking() override;
    void restartWalking() override;
};


#endif //KINGDOMRUSH_STU_TREMOR_H