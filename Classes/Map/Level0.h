//
// Created by 20619 on 2025/11/11.
//

#ifndef KINGDOMRUSH_STU_LEVEL0_H
#define KINGDOMRUSH_STU_LEVEL0_H

#include "Map/BaseMap.h"
#include "cocos2d.h"

USING_NS_CC;

class Level0 : public BaseMap{
public:
    Level0();
    ~Level0();
    static Level0* createGame(int difficulty);
    virtual bool initWithDifficulty(int difficulty);
    void startAfterStory();//动画剧情结束后启动关卡
private:
    void onEnterTransitionDidFinish() override; //生命周期函数，以启动开场动画
    void addOrnament() override;
    void onExit() override;
    void addTerrains() override;

    LayerColor* color;//黑色遮盖层，用于播放开场剧情动画
};


#endif //KINGDOMRUSH_STU_LEVEL0_H