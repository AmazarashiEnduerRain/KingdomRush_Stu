//
// Created by 20619 on 2025/11/20.
// 百科全书场景

#ifndef KINGDOMRUSH_STU_ENCYCLOPEDIASCENE_H
#define KINGDOMRUSH_STU_ENCYCLOPEDIASCENE_H

#include "cocos2d.h"
class EncyclopediaScene : public cocos2d::Layer{
public:
    static cocos2d::Scene* createScene();
    bool init() override;
    CREATE_FUNC(EncyclopediaScene);

    void menuNextCallback1(Ref *pSender);//跳转至游戏提示(Tips)
    void menuNextCallback2(Ref *pSender);//跳转至防御塔百科（Towers）
    void menuNextCallback3(Ref *pSender);//跳转到敌人百科(Enemies)
    void menuNextCallback4(Ref *pSender);//退出百科
};


#endif //KINGDOMRUSH_STU_ENCYCLOPEDIASCENE_H