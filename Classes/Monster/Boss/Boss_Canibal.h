//
// Created by 20619 on 2025/11/20.
// 特殊技能：瞬移；小怪召唤；

#ifndef KINGDOMRUSH_STU_BOSS_CANIBAL_H
#define KINGDOMRUSH_STU_BOSS_CANIBAL_H

#include "Monster/BaseMonster.h"

class Boss_Canibal : public BaseMonster{
public:
    virtual bool init() override;
    static Boss_Canibal* createMonster(std::vector<Point> points,std::vector<std::vector<std::vector<Point>>> sonPath);//由于能够召唤小怪，要传入子代路径

    //特殊的受伤、死亡、爆炸以及冰冻逻辑
    void getHurt() override;
    void death() override;
    void explosion() override;
    void frozen() override;

    //技能相关逻辑
    void beforeSkill(float dt);
    void skill();
    void afterSkill();

    void addSons();//子代召唤

    //瞬移位置控制
    void changePositionLeft();
    void changePositionRight();

    std::vector<std::vector<std::vector<Point>>> sonPath;//子代路径
    Point location;//记录技能释放位置或目标位置
    int skillTag;//记录技能释放次数
};
#endif //KINGDOMRUSH_STU_BOSS_CANIBAL_H