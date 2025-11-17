//
// Created by 20619 on 2025/11/10.
//

#ifndef KINGDOMRUSH_STU_SHIT_H
#define KINGDOMRUSH_STU_SHIT_H


#include "Bullet/Bullet.h"
#include "cocos2d.h"
USING_NS_CC;

class Shit : public Bullet{
public:
    bool init() override;
    CREATE_FUNC(Shit);
    void shoot() override;
    void removeBullet() override;
};

#endif //KINGDOMRUSH_STU_SHIT_H