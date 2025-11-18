//
// Created by 20619 on 2025/11/17.
// 游戏大地图的UI。其包含百科、商店以及升级的入口，并且显示星星与宝石数

#ifndef KINGDOMRUSH_STU_GAMEVIEWMENU_H
#define KINGDOMRUSH_STU_GAMEVIEWMENU_H

#include "cocos2d.h"
USING_NS_CC;

class GameViewMenu : public Layer{
public:
    bool init() override;
    CREATE_FUNC(GameViewMenu);
    void onEnterTransitionDidFinish() override; //在入场过渡动画完成后调用，刷新星星和宝石数并播放入场动画
    MenuItemSprite *book,*shop,*update;
    Sprite* mapStarsContainer;
    bool isFirst;//标记是否是第一次进入（控制是否播放入场动画）
    Label* starLabel;
    Label* diamondsLabel;
};


#endif //KINGDOMRUSH_STU_GAMEVIEWMENU_H