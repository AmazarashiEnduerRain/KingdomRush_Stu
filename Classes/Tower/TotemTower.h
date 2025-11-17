//
// Created by 20619 on 2025/11/8.
//

#ifndef KINGDOMRUSH_STU_TOTEMTOWER_H
#define KINGDOMRUSH_STU_TOTEMTOWER_H

#include "cocos2d.h"
#include "BaseArrowTower.h"

USING_NS_CC;

class TotemTower: public BaseArrowTower{
public:
    bool init() override;
    CREATE_FUNC(TotemTower);
    void showUpdateMenu() override;
    Bullet* ArrowTowerBullet() override;

private:
    void shoot(float dt) override;
    int monstersCount;//射程内的怪物计数
    Sprite* eyesDown;//底部的眼睛动画精灵
    void checkNearestMonster() override;
    void TotemCD(float dt);
    bool totemCD;
};

#endif //KINGDOMRUSH_STU_TOTEMTOWER_H