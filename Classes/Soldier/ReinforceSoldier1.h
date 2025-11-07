//
// Created by 20619 on 2025/11/5.
// 在点击位置召唤援助士兵

#ifndef KINGDOMRUSH_STU_REINFORCESOLDIER1_H
#define KINGDOMRUSH_STU_REINFORCESOLDIER1_H

#include "BaseSoldier.h"
class ReinforceSoldier1 : public BaseSoldier{
public:
    bool init() override;
    CREATE_FUNC(ReinforceSoldier1);
    static ReinforceSoldier1* createReinforceSoldier(Point point);
    void update(float dt) override;
    void attackMonster(float dt) override;

    //创建后调用的辅助函数，用于设置初始状态
    void birth(Point point);

    //重写索敌与移动逻辑（由于援助士兵并不属于防御塔，而是直接添加到地图层）
    void checkNearestMonster() override;
    bool checkDirectionForMonster() override;
    void runToMonster() override;
};


#endif //KINGDOMRUSH_STU_REINFORCESOLDIER1_H