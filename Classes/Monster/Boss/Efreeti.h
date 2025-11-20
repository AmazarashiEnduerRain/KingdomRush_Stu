//
// Created by 20619 on 2025/11/20.
//

#ifndef KINGDOMRUSH_STU_EFREETI_H
#define KINGDOMRUSH_STU_EFREETI_H

#include "Monster/BaseMonster.h"
#include "cocos2d.h"
USING_NS_CC;

class Efreeti : public BaseMonster{
public:
    virtual bool init() override;
    static Efreeti* createMonster(std::vector<Point> points,int pointCounter);
    void getHurt() override;
    void death() override;
    void explosion() override;
};



#endif //KINGDOMRUSH_STU_EFREETI_H