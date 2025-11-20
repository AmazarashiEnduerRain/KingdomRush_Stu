//
// Created by 20619 on 2025/11/3.
// Munra类，一个木乃伊法师

#ifndef KINGDOMRUSH_STU_MUNRA_H
#define KINGDOMRUSH_STU_MUNRA_H

#include "Monster/BaseMonster.h"
#include "cocos2d.h"

USING_NS_CC;

class Munra : public BaseMonster{
public:
    virtual bool init() override;
    static Munra* createMonster(std::vector<Point> points);
};


#endif //KINGDOMRUSH_STU_MUNRA_H