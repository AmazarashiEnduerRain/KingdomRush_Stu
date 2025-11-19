#ifndef KINGDOMRUSH_STU_SHIELD_H
#define KINGDOMRUSH_STU_SHIELD_H

#include "Monster/BaseMonster.h"
#include "cocos2d.h"

USING_NS_CC;

class Shield : public BaseMonster{
public:
    virtual bool init() override;
    static Shield* createMonster(std::vector<Point> points);
};


#endif //KINGDOMRUSH_STU_SHIELD_H