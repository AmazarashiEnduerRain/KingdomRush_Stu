//
// Created by 20619 on 2025/11/10.
//

#ifndef KINGDOMRUSH_STU_VIOLETTOTEM_H
#define KINGDOMRUSH_STU_VIOLETTOTEM_H

#include "cocos2d.h"
#include "Bullet/Bullet.h"

USING_NS_CC;

class VioletTotem : public Bullet{
public:
    static VioletTotem* createVioletTotem(Point point);
    bool init() override;
    CREATE_FUNC(VioletTotem);
    void shoot(Point location);
    void removeBullet() override;
    void boom();
};


#endif //KINGDOMRUSH_STU_VIOLETTOTEM_H