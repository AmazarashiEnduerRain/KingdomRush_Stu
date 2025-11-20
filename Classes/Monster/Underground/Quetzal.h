//
// Created by 20619 on 2025/11/20.
//

#ifndef KINGDOMRUSH_STU_QUETZAL_H
#define KINGDOMRUSH_STU_QUETZAL_H

#include "Monster/BaseMonster.h"
#include "cocos2d.h"
USING_NS_CC;

class Quetzal : public BaseMonster{
public:
    virtual bool init() override;
    static Quetzal* createMonster(std::vector<Point> points);
};


#endif //KINGDOMRUSH_STU_QUETZAL_H