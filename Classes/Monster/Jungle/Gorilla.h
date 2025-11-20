#ifndef KINGDOMRUSH_STU_GORILLA_H
#define KINGDOMRUSH_STU_GORILLA_H

#include "Monster/BaseMonster.h"
#include "cocos2d.h"

USING_NS_CC;

class Gorilla : public BaseMonster{
public:
    virtual bool init() override;
    static Gorilla* createMonster(std::vector<Point> points);
};


#endif //KINGDOMRUSH_STU_GORILLA_H