//
// Created by 20619 on 2025/11/9.
//

#ifndef KINGDOMRUSH_STU_MECHA_H
#define KINGDOMRUSH_STU_MECHA_H

#include "BaseSoldier.h"
#include "Bullet/Bomb.h"

class Mecha : public BaseSoldier{
public:
    bool init() override;
    CREATE_FUNC(Mecha);
    void runToLocation(Point location) override;//重写移动函数。在移动时停止攻击，抵达位置后恢复
private:
    void shootMissiles();//远程导弹轰炸
    void bombMonster(float dt);
    void checkNearestMonster() override;
    void checkFarestMonster();//寻找远处敌人（用于导弹轰炸）
    Bomb* MechaBullet();
    BaseMonster* farestMonster1;
    BaseMonster* farestMonster2;

    int monsterCount;//计数怪物数量，用于触发漏油技能
    Sprite* shit;//播放油污动画的精灵对象
    void addShit();
    void shitting();
    void shitCD(float dt);
    bool couldShit;
};


#endif //KINGDOMRUSH_STU_MECHA_H