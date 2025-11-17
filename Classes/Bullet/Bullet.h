//
// Created by 20619 on 2025/10/25.
//

#ifndef KINGDOMRUSH_STU_BULLET_H
#define KINGDOMRUSH_STU_BULLET_H

#include "Data/SoundManager.h"
#include "cocos2d.h"
#include "Data/GameManager.h"

USING_NS_CC;

class Bullet : public Sprite{
public:
    Bullet();
    ~Bullet();
    bool init() override;//重写Sprite的init方法，用于初始化
    CREATE_FUNC(Bullet);//用于创建对象的静态方法

protected:
    CC_SYNTHESIZE(int, maxForce, MaxForce);//子弹伤害
    CC_SYNTHESIZE(int, bulletScope, BulletScope);//子弹攻击范围（与炸弹相关）
    CC_SYNTHESIZE(int, bulletType, BulletType);//子弹类型标识
    CC_SYNTHESIZE(Spawn*, bulletAction, BulletAction);//子弹动作
    Sprite* sprite;//指向子弹自身的精灵图像

    virtual void shoot(){};
    virtual void removeBullet(){};//需要在子类中具体实现发射子弹和子弹移除的逻辑
};

#endif //KINGDOMRUSH_STU_BULLET_H
