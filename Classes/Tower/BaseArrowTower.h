//
// Created by 20619 on 2025/10/23.
//

#ifndef KINGDOMRUSH_STU_BASEARROWTOWER_H
#define KINGDOMRUSH_STU_BASEARROWTOWER_H

#include "cocos2d.h"
#include "Tower/BaseTower.h" //父类头文件
#include "Bullet/Bullet.h" //子弹类头文件

#define LEFT_ARCHER_SHOT 1
#define RIGHT_ARCHER_SHOT 2 //标记射手

USING_NS_CC;

class BaseArrowTower : public BaseArrowTower{
public:
//从父类继承
protected:
    Sprite* shooter_1;
    Sprite* shooter_2;//两个射手精灵
    Sprite* towerBase;//塔基座精灵
    int shootTag;//标记下一次该哪个射手射击
    void initTower(int level);//初始化塔外观
    void addTerrain();//添加特定地形外观
    virtual Bullet* ArrowTowerBullet();//创建箭矢的虚函数，由具体子类实现
    virtual void shoot(float dt);//射击的虚函数，由具体子类实现
};


#endif //KINGDOMRUSH_STU_BASEARROWTOWER_H