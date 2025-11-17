//
// Created by 20619 on 2025/11/10.
//

#ifndef KINGDOMRUSH_STU_SMOKE_H
#define KINGDOMRUSH_STU_SMOKE_H

#include "cocos2d.h"
#include "Bullet/Bullet.h"
USING_NS_CC;
class Smoke:public Bullet{
public:
    bool init() override;
    CREATE_FUNC(Smoke);
    void fadeSmoke(Animation*,float);
    void remove();
};

#endif //KINGDOMRUSH_STU_SMOKE_H