//
// Created by 20619 on 2025/11/10.
//

#ifndef KINGDOMRUSH_STU_DRILL_H
#define KINGDOMRUSH_STU_DRILL_H

#include "cocos2d.h"
#include "Bullet/Bullet.h"
#include "Monster/BaseMonster.h"

USING_NS_CC;
class Drill : public Bullet{
public:
    bool init() override;
    CREATE_FUNC(Drill);
    void shoot() override;//启动钻头，选择目标并造成伤害
    void removeBullet() override;
    void DrillMonster(float dt);
    Sprite* drill;//视觉精灵
    BaseMonster* monsterToBeDrilled;
};


#endif //KINGDOMRUSH_STU_DRILL_H