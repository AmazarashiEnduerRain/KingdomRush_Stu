//
// Created by 20619 on 2025/10/23.
//

#ifndef KINGDOMRUSH_STU_BASEMAGETOWER_H
#define KINGDOMRUSH_STU_BASEMAGETOWER_H

#include "cocos2d.h"
#include "Tower/BaseTower.h"
#include "Bullet/Bullet.h"
USING_NS_CC;

class BaseMageTower : public BaseTower{
public:

protected:
    Sprite* shooter;//指向施法者精灵
    Sprite* towerBase;//指向塔基座
    Bullet* currBullet;//指向当前准备发射的子弹
    void initTower(int level);//初始化塔外观
    void addTerrain();//添加具体地形外观

    virtual Bullet* MageTowerBullet(); //创建魔法弹的虚函数，由具体子类实现
    void shoot(float dt);//射击逻辑
};


#endif //KINGDOMRUSH_STU_BASEMAGETOWER_H