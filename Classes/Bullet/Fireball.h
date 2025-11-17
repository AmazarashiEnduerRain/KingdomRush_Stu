//
// Created by 20619 on 2025/11/10.
// 玩家召唤的陨石技能

#ifndef KINGDOMRUSH_STU_FIREBALL_H
#define KINGDOMRUSH_STU_FIREBALL_H

#include "cocos2d.h"
#include "Bullet/Bullet.h"

class FireBall : public Bullet{
public :
    bool init() override;
    CREATE_FUNC(FireBall);
    void shoot(Point location);
    void removeBullet() override;
    void smoke(float dt);//下落过程中持续产生烟雾粒子
    void round();//播放陨石循环动画
    void explosion();//爆炸动画
};


#endif //KINGDOMRUSH_STU_FIREBALL_H