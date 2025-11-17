//
// Created by 20619 on 2025/11/10.
//

#ifndef KINGDOMRUSH_STU_REDTOTEM_H
#define KINGDOMRUSH_STU_REDTOTEM_H

#include "cocos2d.h"
#include "Bullet/Bullet.h"

USING_NS_CC;

class RedTotem : public Bullet{
public:
    static RedTotem* createRedTotem(Point point);
    bool init() override;
    CREATE_FUNC(RedTotem);
    void shoot(Point location);//图腾直接在相应位置被召唤
    void removeBullet() override;
    void boom();//对范围内敌人造成伤害
};


#endif //KINGDOMRUSH_STU_REDTOTEM_H