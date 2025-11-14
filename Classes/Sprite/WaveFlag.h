//
// Created by 20619 on 2025/11/14.
//

#ifndef KINGDOMRUSH_STU_WAVEFLAG_H
#define KINGDOMRUSH_STU_WAVEFLAG_H

#include "cocos2d.h"
USING_NS_CC;

class WaveFlag : public Sprite{
public:
    virtual bool WaveFlagInit();
    CREATE_FUNC(WaveFlag);
    static WaveFlag* createWaveFlag();

    float getWavePercentage();
    void restartWaveFlag();
    void stopRespiration();//停止动画并隐藏旗帜，用于处理玩家点击旗帜、提前开始波次
    void setWavePercentage(float per);

    ProgressTimer* waveProgressTimer;//实现圆形进度条的加载效果
    Sprite* selected;//显示旗帜被“选中”时的高亮边框
    bool isShown;//标志旗帜是否可见
    void setSelected();
private:
    float percentage;//用于在startRespiration动画中跟踪进度
    void startRespiration(float dt);//实现旗帜的“呼吸”和圆形进度加载动画
};


#endif //KINGDOMRUSH_STU_WAVEFLAG_H