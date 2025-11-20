//
// Created by 20619 on 2025/11/3.
//

#ifndef KINGDOMRUSH_STU_EXECUTIONER_H
#define KINGDOMRUSH_STU_EXECUTIONER_H

#include "Monster/BaseMonster.h"
#include "cocos2d.h"

USING_NS_CC;

class Executioner : public BaseMonster{
public:
    virtual bool init() override;
    static Executioner* createMonster(std::vector<Point> points);
};


#endif //KINGDOMRUSH_STU_EXECUTIONER_H