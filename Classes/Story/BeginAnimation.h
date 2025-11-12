//
// Created by 20619 on 2025/11/12.
//

#ifndef KINGDOMRUSH_STU_BEGINANIMATION_H
#define KINGDOMRUSH_STU_BEGINANIMATION_H

#include "cocos2d.h"
#include "Map/Level0.h"
USING_NS_CC;
class BeginAnimation : public Layer{
public:
    static Scene* createScene();
    CREATE_FUNC(BeginAnimation);

    bool init() override;

    void startAnimation1();
    void startAnimation2();//两页动画

    void backToGame();//在动画播放完毕后返回游戏主逻辑
    Level0* game;
protected:
    Sprite* continue_btn;//指向继续按钮
    Sprite* sp1,*sp2,*sp3;//用于显示不同漫画图块的视觉精灵
};

#endif //KINGDOMRUSH_STU_BEGINANIMATION_H