//
// Created by 20619 on 2025/11/10.
// 熔岩视觉特效

#ifndef KINGDOMRUSH_STU_LAVA_H
#define KINGDOMRUSH_STU_LAVA_H

#include "cocos2d.h"
#include "Bullet/Bullet.h"

USING_NS_CC;
class Lava : public Bullet{
public :
    bool init() override;
    CREATE_FUNC(Lava);
    void shoot() override;
};


#endif //KINGDOMRUSH_STU_LAVA_H