//
// Created by 20619 on 2025/11/7.
//

#ifndef KINGDOMRUSH_STU_COSSBOWHUNTERTOWER_H
#define KINGDOMRUSH_STU_COSSBOWHUNTERTOWER_H

#include "cocos2d.h"
#include "BaseArrowTower.h"
USING_NS_CC;
class CossbowHunterTower: public BaseArrowTower{
public:
    bool init() override;
    CREATE_FUNC(CossbowHunterTower);
    void showUpdateMenu() override;//菜单此时只显示售卖
    Bullet* ArrowTowerBullet() override;

private:
    void shoot(float dt) override;
    int attackCount; //攻击计数，用于触发特殊技能
    Sprite* hawk; //呈现老鹰飞旋的装饰性动画
};

#endif //KINGDOMRUSH_STU_COSSBOWHUNTERTOWER_H