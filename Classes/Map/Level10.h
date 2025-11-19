//
// Created by 20619 on 2025/11/11.
//

#ifndef KINGDOMRUSH_STU_LEVEL10_H
#define KINGDOMRUSH_STU_LEVEL10_H

#include "Map/BaseMap.h"
#include "cocos2d.h"
USING_NS_CC;

class Level10 : public BaseMap{
public:
    Level10();
    ~Level10();
    static Level10* createGame(int difficulty);
    virtual bool initWithDifficulty(int difficulty);
private:
    void addOrnament() override;
    void onExit() override;
    void addTerrains() override;

    Sprite* stageTower;//关卡中央的塔，播放动画以实现Boss的出场效果
    void waveEvent() override;
};
#endif //KINGDOMRUSH_STU_LEVEL10_H