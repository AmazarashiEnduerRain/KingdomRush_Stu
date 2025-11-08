//
// Created by 20619 on 2025/11/8.
//

#ifndef KINGDOMRUSH_STU_ARCHMAGETOWER_H
#define KINGDOMRUSH_STU_ARCHMAGETOWER_H

#include "cocos2d.h"
#include "BaseMageTower.h"

USING_NS_CC;

class ArchMageTower: public BaseMageTower{
public:
    bool init() override;
    CREATE_FUNC(ArchMageTower);

    void getTwister(int level);
    void getForce(int level);

    void showUpdateMenu() override;
    Bullet* MageTowerBullet() override;

    //攻击逻辑、龙卷风逻辑
    void Attack(float dt);
    void AtTwister(float dt);

    //确保售卖时所有存储的盘旋子弹等也被清除
    void sellTower() override;
private:
    void buildDelayBullet();//创建盘旋蓄力子弹
    Bullet* DelayBullet[3];//储存蓄力子弹的数组
};


#endif //KINGDOMRUSH_STU_ARCHMAGETOWER_H