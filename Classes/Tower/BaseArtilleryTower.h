//
// Created by 20619 on 2025/10/24.
//

#ifndef KINGDOMRUSH_STU_BASEARTILLERYTOWER_H
#define KINGDOMRUSH_STU_BASEARTILLERYTOWER_H

#include "cocos2d.h"
#include "Tower/BaseTower.h"
#include "Bullet/Bullet.h"

USING_NS_CC;

class BaseArtilleryTower : public BaseTower{
public:

protected:
    void initTower(int level);
    void addTerrain();
    virtual Bullet* ArtilleryTowerBullet();//创建炮弹
    void shoot(float dt);//攻击
    Sprite* towerBase;//炮塔基座
    Sprite* leftShooter;//左边炮手
    Sprite* rightShooter;//右边炮手
    Sprite* c4;//炸弹
    Sprite* barrel;//炮筒
    Sprite* smoke;//烟
    bool isReady;//炮弹是否填充完毕（上一发炮是否打完）
    void filledAnimation();//填充炮弹动画
    void fireAnimation();//发射炮弹动画
    void fire(Point firePosition);//发射炮弹
private:
    void checkNearestMonster() override;//重写基类索敌方法（炮塔仅能攻击地面单位）
};


#endif //KINGDOMRUSH_STU_BASEARTILLERYTOWER_H