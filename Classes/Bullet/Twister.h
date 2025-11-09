//
// Created by 20619 on 2025/11/9.
//

#ifndef KINGDOMRUSH_STU_TWISTER_H
#define KINGDOMRUSH_STU_TWISTER_H

#include "cocos2d.h"
#include "Bullet/Bullet.h"
#include "Monster/BaseMonster.h"

class Twister:public Bullet{
public:
    bool init() override;
    CREATE_FUNC(Twister);
    void round();//龙卷风生成动画
    void attackMonster();//切换到攻击状态，开始循环动画和伤害/移动逻辑
    void hitMonster(float dt);
    void move(float dt);//龙卷风向怪物移动
    void removeTwister();
    void removeTwisterAction(float dt);
    void checkNearestMonster();

    BaseMonster* nearestMonster;
};


#endif //KINGDOMRUSH_STU_TWISTER_H