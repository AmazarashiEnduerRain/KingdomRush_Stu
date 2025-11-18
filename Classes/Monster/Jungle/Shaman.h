#ifndef KINGDOMRUSH_STU_SHAMAN_H
#define KINGDOMRUSH_STU_SHAMAN_H

#include "Monster/BaseMonster.h"
#include "cocos2d.h"

USING_NS_CC;

class Shaman : public BaseMonster{
public:
    virtual bool init() override;
    static Shaman* createMonster(std::vector<Point> points);
};


#endif //KINGDOMRUSH_STU_SHAMAN_H