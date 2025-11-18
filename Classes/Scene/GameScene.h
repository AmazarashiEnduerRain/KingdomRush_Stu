//
// Created by 20619 on 2025/11/18.
// 根据传入的关卡与难度，加载对应的地图层并加载playerStateMenu

#ifndef KINGDOMRUSH_STU_GAMESCENE_H
#define KINGDOMRUSH_STU_GAMESCENE_H

#include "cocos2d.h"
USING_NS_CC;

class GameScene : public Scene{
public:
    virtual bool initGame(int Level,int Difficulty);
    static Scene* playGame(int Level,int Difficulty);
};


#endif //KINGDOMRUSH_STU_GAMESCENE_H