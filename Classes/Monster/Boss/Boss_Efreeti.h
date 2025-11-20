//
// Created by 20619 on 2025/11/20.
//

#ifndef KINGDOMRUSH_STU_BOSS_EFREETI_H
#define KINGDOMRUSH_STU_BOSS_EFREETI_H

#include "Monster/BaseMonster.h"

class Boss_Efreeti : public BaseMonster{
public:
    virtual bool init() override;
    static Boss_Efreeti* createMonster(std::vector<Point> points,std::vector<std::vector<std::vector<Point>>> sonPath);

    void getHurt() override;
    void death() override;
    void explosion() override;
    void frozen() override;

    void skill(float dt);
    void addSons();
    void laugh();

    std::vector<std::vector<std::vector<Point>>> sonPath;
    Sprite* cloud;
};


#endif //KINGDOMRUSH_STU_BOSS_EFREETI_H