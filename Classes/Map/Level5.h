//
// Created by 20619 on 2025/11/11.
// boss关卡

#ifndef KINGDOMRUSH_STU_LEVEL5_H
#define KINGDOMRUSH_STU_LEVEL5_H

#include "Map/BaseMap.h"
#include "cocos2d.h"

USING_NS_CC;

class Level5 : public BaseMap{
public:
    Level5();
    ~Level5();
    static Level5* createGame(int difficulty);
    virtual bool initWithDifficulty(int difficulty);

private:
    void addOrnament() override;
    void onExit() override;
    void addTerrains() override;
    Sprite* door;//boss登场时的大门视觉精灵
    void waveEvent() override;//重写waveEvent以处理boss登场

    void eyeEffect();//大门上眼睛发光的动画
    void stonesEffect();//门打开时石头掉落的特效
    void beforeBoss();//镜头移动
};


#endif //KINGDOMRUSH_STU_LEVEL5_H