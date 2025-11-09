//
// Created by 20619 on 2025/11/9.
//

#ifndef KINGDOMRUSH_STU_ARCHMAGEBOLT_H
#define KINGDOMRUSH_STU_ARCHMAGEBOLT_H

#include "cocos2d.h"
#include "Bullet/Bullet.h"
class ArchMageBolt:public Bullet{
public :
    bool init() override;
    CREATE_FUNC(ArchMageBolt);
    void shoot() override;
    void removeBullet() override;
    void round();
};


#endif //KINGDOMRUSH_STU_ARCHMAGEBOLT_H