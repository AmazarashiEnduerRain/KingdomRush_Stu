//
// Created by 20619 on 2025/11/9.
//

#ifndef KINGDOMRUSH_STU_SKELETON_H
#define KINGDOMRUSH_STU_SKELETON_H

#include "BaseSoldier.h"

class Skeleton : public BaseSoldier{
public:
    bool init() override;
    CREATE_FUNC(Skeleton);
    static Skeleton* createSkeleton(Point point);
    void update(float dt) override;
    void attackMonster(float dt) override;
    void birth(Point point);

    //处于不同层级，坐标计算方式不同，需要对函数进行重写
    void runToMonster() override;
    bool checkDirectionForMonster() override;
    void checkNearestMonster() override;
    void createAndSetHpBar() override;
};

#endif //KINGDOMRUSH_STU_SKELETON_H