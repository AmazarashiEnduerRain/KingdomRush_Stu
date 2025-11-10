//
// Created by 20619 on 2025/11/10.
//

#ifndef KINGDOMRUSH_STU_MISSILE_H
#define KINGDOMRUSH_STU_MISSILE_H

#include "cocos2d.h"
#include "Bullet/Bullet.h"
#include "Monster/BaseMonster.h"

USING_NS_CC;

class Missile : public Bullet{
public:
    bool init() override;
    CREATE_FUNC(Missile);
    void shoot(BaseMonster* monster,Point mechaPosition);//会对怪物血量进行检查
    void removeBullet() override;
    BaseMonster* monsterToBeDrilled;
};


#endif //KINGDOMRUSH_STU_MISSILE_H