//
// Created by 20619 on 2025/11/10.
// 在指定位置施加的冰冻法术道具

#ifndef KINGDOMRUSH_STU_FREEZE_H
#define KINGDOMRUSH_STU_FREEZE_H

#include "cocos2d.h"
#include "Bullet/Bullet.h"
USING_NS_CC;

class Freeze : public Bullet{
public:
    bool init() override;
    CREATE_FUNC(Freeze);
    void shoot(Point point);
    void removeBullet() override;
};


#endif //KINGDOMRUSH_STU_FREEZE_H