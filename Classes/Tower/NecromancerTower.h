//
// Created by 20619 on 2025/11/8.
//

#ifndef KINGDOMRUSH_STU_NECROMANCERTOWER_H
#define KINGDOMRUSH_STU_NECROMANCERTOWER_H

#include "cocos2d.h"
#include "BaseMageTower.h"
#include "Soldier/DeathKnight.h"
USING_NS_CC;

class NecromancerTower: public BaseMageTower{
public:
    bool init() override;
    CREATE_FUNC(NecromancerTower);
    Bullet* MageTowerBullet() override;
    void Attack(float dt);
    void setRallyPoint(Point location) override;//调动死亡骑士
private:
    DeathKnight* deathKnight;//塔包含一个死亡骑士宠物
    void showUpdateMenu() override;
    void cureSoldiers(float dt);//每十秒检查死亡骑士状态
    Sprite* glow;//攻击时的发光特效
};



#endif //KINGDOMRUSH_STU_NECROMANCERTOWER_H