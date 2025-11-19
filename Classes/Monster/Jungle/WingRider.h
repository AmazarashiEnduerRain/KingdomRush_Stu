#ifndef KINGDOMRUSH_STU_WINGRIDER_H
#define KINGDOMRUSH_STU_WINGRIDER_H

#include "Monster/BaseMonster.h"
#include "cocos2d.h"

USING_NS_CC;

class WingRider : public BaseMonster{
public:
    virtual bool init() override;
    static WingRider* createMonster(std::vector<Point> points);
};


#endif //KINGDOMRUSH_STU_WINGRIDER_H