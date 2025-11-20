//
// Created by 20619 on 2025/11/19.
// 预加载资源界面（进入游戏之前的显示）

#ifndef KINGDOMRUSH_STU_LOADINGSCENE_H
#define KINGDOMRUSH_STU_LOADINGSCENE_H

#include "cocos2d.h"
USING_NS_CC;

class LoadingScene : public Layer{
public:
    static Scene* createScene();
    bool init() override;
    CREATE_FUNC(LoadingScene);

    void loadSouce();//进行资源加载
    void logic(float dt);//每帧调用的逻辑函数，用于检查加载进度
    int numberOfLoadedRes;//加载进度计数器
};


#endif //KINGDOMRUSH_STU_LOADINGSCENE_H