//
// Created by 20619 on 2025/11/4.
//

#ifndef KINGDOMRUSH_STU_FALLEN_H
#define KINGDOMRUSH_STU_FALLEN_H

#include "Monster/BaseMonster.h"
#include "cocos2d.h"

USING_NS_CC;

class Fallen : public BaseMonster{
public:
    virtual bool init() override;

    //两套createMonster函数，以进行不同的产生逻辑
    static Fallen* createMonster(std::vector<Point> points);
    static Fallen* createMonster(std::vector<Point> points,Point birthLocation,int pointCounter);
    void birth(Point birthLocation,int pointCounter); //特殊的出生逻辑
};


#endif //KINGDOMRUSH_STU_FALLEN_H