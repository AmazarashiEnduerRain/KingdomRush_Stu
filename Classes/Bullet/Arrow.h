//
// Created by 20619 on 2025/10/25.
//

#ifndef KINGDOMRUSH_STU_ARROW_H
#define KINGDOMRUSH_STU_ARROW_H

#include "cocos2d.h"
#include "Bullet/Bullet.h"

USING_NS_CC;

class Arrow : public Bullet{
public:
    bool init() override;
    CREATE_FUNC(Arrow);
    void shoot() override;
    void removeBullet() override;
};


#endif //KINGDOMRUSH_STU_ARROW_H