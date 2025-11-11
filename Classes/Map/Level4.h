//
// Created by 20619 on 2025/11/11.
//

#ifndef KINGDOMRUSH_STU_LEVEL4_H
#define KINGDOMRUSH_STU_LEVEL4_H

#include "Map/BaseMap.h"
#include "cocos2d.h"

USING_NS_CC;

class Level4 : public BaseMap{
public:
    Level4();
    ~Level4();
    static Level4* createGame(int difficulty);
    virtual bool initWithDifficulty(int difficulty);

private:
    void addOrnament() override;
    void onExit() override;
    void initAction();
    void treeCover();
    void addTerrains() override;
    void waveEvent() override;//有船门开启的动画

    //关卡的特殊视觉精灵
    Sprite* doorSprite;
    Sprite* TreeSprite[4][3];
    Sprite* treeTerrains[4];
};



#endif //KINGDOMRUSH_STU_LEVEL4_H