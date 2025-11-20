//
// Created by 20619 on 2025/11/4.
//

#ifndef KINGDOMRUSH_STU_IM_H
#define KINGDOMRUSH_STU_IM_H

#include "Monster/BaseMonster.h"
#include "cocos2d.h"

USING_NS_CC;

class Immortal : public BaseMonster{
public:
    virtual bool init() override;
    static Immortal* createMonster(std::vector<Point> points);

    //重写死亡、爆炸的逻辑（其死后会生成fallen怪物）
    void death() override;
    void explosion() override;
    Point nextPoint();
};


#endif //KINGDOMRUSH_STU_IM_H