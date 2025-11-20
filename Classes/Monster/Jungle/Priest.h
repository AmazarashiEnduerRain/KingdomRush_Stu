#ifndef KINGDOMRUSH_STU_PRIEST_H
#define KINGDOMRUSH_STU_PRIEST_H

#include "Monster/BaseMonster.h"
#include "cocos2d.h"

USING_NS_CC;

class Priest : public BaseMonster{
public:
    virtual bool init() override;
    static Priest* createMonster(std::vector<Point> points);
};


#endif //KINGDOMRUSH_STU_PRIEST_H