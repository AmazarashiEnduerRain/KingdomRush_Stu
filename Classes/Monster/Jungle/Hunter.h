#ifndef KINGDOMRUSH_STU_HUNTER_H
#define KINGDOMRUSH_STU_HUNTER_H

#include "Monster/BaseMonster.h"
#include "cocos2d.h"

USING_NS_CC;

class Hunter : public BaseMonster{
public:
    virtual bool init() override;
    static Hunter* createMonster(std::vector<Point> points);
};


#endif //KINGDOMRUSH_STU_HUNTER_H