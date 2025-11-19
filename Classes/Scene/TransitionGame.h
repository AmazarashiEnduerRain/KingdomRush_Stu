//
// Created by 20619 on 2025/11/19.
// 这是一个过渡场景动画类，继承自TransitionScene

#ifndef KINGDOMRUSH_STU_TRANSITIONGAME_H
#define KINGDOMRUSH_STU_TRANSITIONGAME_H

#include <cocos2d.h>
USING_NS_CC;

class TransitionGame : public TransitionScene{
public:
    TransitionGame();
    virtual ~TransitionGame();
    void onEnter() override;

    static TransitionGame *create(float t, Scene *scene);//标准创建函数：传入持续时间和目标场景
    static TransitionGame *createWithRenderTexture(float t, Scene *scene, RenderTexture *sqr);//带有渲染纹理的创建
private:
    void initRenderTexture(RenderTexture *sqr);
    void LRFinish();//转场结束
    void OnSecondActionFinish();//第一阶段（关门结束）
    int m_FinishCnt;
};


#endif //KINGDOMRUSH_STU_TRANSITIONGAME_H