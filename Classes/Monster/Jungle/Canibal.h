#ifndef KINGDOMRUSH_STU_CANIBAL_H
#define KINGDOMRUSH_STU_CANIBAL_H

#include "Monster/BaseMonster.h"
#include "cocos2d.h"

USING_NS_CC;

class Canibal : public BaseMonster{
public:
    virtual bool init() override;
    static Canibal* createMonster(std::vector<Point> points);
};


#endif //KINGDOMRUSH_STU_CANIBAL_H