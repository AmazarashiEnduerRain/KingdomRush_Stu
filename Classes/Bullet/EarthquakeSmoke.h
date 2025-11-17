//
// Created by 20619 on 2025/11/10.
// 视觉特效类。十二个烟雾精灵圆形排列，模拟震击效果

#ifndef KINGDOMRUSH_STU_EARTHQUAKESMOKE_H
#define KINGDOMRUSH_STU_EARTHQUAKESMOKE_H

#include "cocos2d.h"
#include "Bullet/Bullet.h"

class EarthquakeSmoke:public Bullet{
public :
    bool init() override;
    CREATE_FUNC(EarthquakeSmoke);
    void shoot() override;
    Vector<Sprite*> smokes;
};


#endif //KINGDOMRUSH_STU_EARTHQUAKESMOKE_H