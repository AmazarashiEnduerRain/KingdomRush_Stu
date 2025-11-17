//
// Created by 20619 on 2025/10/26.
//

#ifndef KINGDOMRUSH_STU_BOMB_H
#define KINGDOMRUSH_STU_BOMB_H

#include "cocos2d.h"
#include "Bullet/Bullet.h"

USING_NS_CC;

class Bomb : public Bullet{
public:
    static Bomb* createBombWithType(int type);
    virtual bool initWithType(int type); //根据类型进行初始化和创建
    int type;
    CREATE_FUNC(Bomb);
    void shoot() override;
    void removeBullet() override;
};


#endif //KINGDOMRUSH_STU_BOMB_H