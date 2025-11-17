//
// Created by 20619 on 2025/11/10.
// 直接由玩家放置在地图上的炸药道具

#ifndef KINGDOMRUSH_STU_DYNAMITE_H
#define KINGDOMRUSH_STU_DYNAMITE_H

#include "cocos2d.h"
#include "Bullet/Bullet.h"

USING_NS_CC;

class Dynamite : public Bullet{
public:
    bool init() override;
    CREATE_FUNC(Dynamite);
    void shoot(Point point);//由于直接放在地图上，故传入坐标参数
    void removeBullet() override;
};


#endif //KINGDOMRUSH_STU_DYNAMITE_H