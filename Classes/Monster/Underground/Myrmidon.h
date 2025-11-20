//
// Created by 20619 on 2025/11/20.
//

#ifndef KINGDOMRUSH_STU_MYRMIDON_H
#define KINGDOMRUSH_STU_MYRMIDON_H

#include "Monster/BaseMonster.h"
#include "cocos2d.h"
USING_NS_CC;

class Myrmidon : public BaseMonster{
public:
    virtual bool init() override;
    static Myrmidon* createMonster(std::vector<Point> points);
};
#endif //KINGDOMRUSH_STU_MYRMIDON_H