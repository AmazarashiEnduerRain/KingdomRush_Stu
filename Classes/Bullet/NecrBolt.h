//
// Created by 20619 on 2025/11/9.
//

#ifndef KINGDOMRUSH_STU_NECRBOLT_H
#define KINGDOMRUSH_STU_NECRBOLT_H

#include "cocos2d.h"
#include "Bullet/Bullet.h"

class NecrBolt : public Bullet{
public :
    bool init() override;
    CREATE_FUNC(NecrBolt);
    void shoot() override;
    void removeBullet() override;
};


#endif //KINGDOMRUSH_STU_NECRBOLT_H