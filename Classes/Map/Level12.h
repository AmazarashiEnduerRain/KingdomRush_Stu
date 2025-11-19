//
// Created by 20619 on 2025/11/11.
//

#ifndef KINGDOMRUSH_STU_LEVEL12_H
#define KINGDOMRUSH_STU_LEVEL12_H

#include "Map/BaseMap.h"
#include "cocos2d.h"

USING_NS_CC;

class Level12 : public BaseMap{
public:
    Level12();
    ~Level12();
    static Level12* createGame(int difficulty);
    virtual bool initWithDifficulty(int difficulty);
private:
    void addOrnament() override;
    void onExit() override;
    void addTerrains() override;
};

#endif //KINGDOMRUSH_STU_LEVEL12_H