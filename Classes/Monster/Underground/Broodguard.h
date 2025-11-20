//
// Created by 20619 on 2025/11/20.
//

#ifndef KINGDOMRUSH_STU_BROODGUARD_H
#define KINGDOMRUSH_STU_BROODGUARD_H

#include "Monster/BaseMonster.h"
#include "cocos2d.h"
USING_NS_CC;

class Broodguard : public BaseMonster{
public:
    virtual bool init() override;
    static Broodguard* createMonster(std::vector<Point> points);
};


#endif //KINGDOMRUSH_STU_BROODGUARD_H