//
// Created by 20619 on 2025/11/17.
// 胜利界面

#ifndef KINGDOMRUSH_STU_VICTORY_H
#define KINGDOMRUSH_STU_VICTORY_H

#include "cocos2d.h"
USING_NS_CC;

class Victory : public Layer{
public:
    virtual bool initVictory(int star,int gem);
    static Victory* createVictory(int star,int gem);//接收获得的宝石数、星星数
    void OnRestartTouch(Ref* pSpender);
    void OnContinueTouch(Ref* pSpender);

    void VSpriteAnimation();//胜利图标动画
    void CItemAnimation();//继续按钮动画
    void RItemAnimation();//重玩按钮动画

    CREATE_FUNC(Victory);

    int level;
    int difficult;//保存关卡以及难度等级
private:
    Sprite* win_Gnome;//显示胜利时获得宝石的矮人图标
    Point position;//胜利徽章的位置
    Sprite* VictorySprite;//胜利徽章
    MenuItemSprite* ContinueMenuItem;
    MenuItemSprite* RestartMenuItem;//继续和重玩按钮

    void showStar(int star);
    void showGems();//显示星星、宝石动画
};
#endif //KINGDOMRUSH_STU_VICTORY_H