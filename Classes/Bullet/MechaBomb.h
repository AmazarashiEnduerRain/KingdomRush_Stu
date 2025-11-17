//
// Created by 20619 on 2025/11/10.
//

#ifndef KINGDOMRUSH_STU_MECHABOMB_H
#define KINGDOMRUSH_STU_MECHABOMB_H

#include "cocos2d.h"
#include "Bullet/Bullet.h"

USING_NS_CC;
class MechaBomb : public Bullet{
public:
    bool init() override;
    CREATE_FUNC(MechaBomb);
    void shoot() override;
    void removeBullet() override;
};


#endif //KINGDOMRUSH_STU_MECHABOMB_H