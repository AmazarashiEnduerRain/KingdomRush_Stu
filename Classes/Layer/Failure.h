//
// Created by 20619 on 2025/11/17.
//

#ifndef KINGDOMRUSH_STU_FAILURE_H
#define KINGDOMRUSH_STU_FAILURE_H
#include "cocos2d.h"
USING_NS_CC;

class Failure : public Layer{
public:
    bool init() override;
    void initMap();
    CREATE_FUNC(Failure);
    int level;
    int difficulty;
private:
    void pauseGame();//暂停游戏逻辑
    void initOption();//背景板绘制
    Sprite* option;//UI面板的容器
    bool onTouchBegan(Touch* touch, Event* event) override;
    void onTouchEnded(Touch* touch, Event* event) override;
};
#endif //KINGDOMRUSH_STU_FAILURE_H