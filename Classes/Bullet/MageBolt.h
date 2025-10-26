//
// Created by 20619 on 2025/10/26.
//

#ifndef KINGDOMRUSH_STU_MAGEBOLT_H
#define KINGDOMRUSH_STU_MAGEBOLT_H

#include "cocos2d.h"
#include "Bullet/Bullet.h"

USING_NS_CC;

class MageBolt : public Bullet{
public:
    bool init() override;
    CREATE_FUNC(MageBolt);
    void shoot() override;
    void removeBullet() override;
};

#endif //KINGDOMRUSH_STU_MAGEBOLT_H