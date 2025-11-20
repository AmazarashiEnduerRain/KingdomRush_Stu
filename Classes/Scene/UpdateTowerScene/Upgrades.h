//
// Created by 20619 on 2025/11/18.
// 升级界面。管理5 * 6的升级矩阵

#ifndef KINGDOMRUSH_STU_UPGRADES_H
#define KINGDOMRUSH_STU_UPGRADES_H

#include "cocos2d.h"
#include "Icons.h"
USING_NS_CC;

class Upgrades :public Layer{
public:
    static Scene* createScene();
    bool init() override;
    CREATE_FUNC(Upgrades);

    void initialState();//初始化图标状态
    void initialOriginalSta();//初始化原始状态
protected:
    Icons::IconsStatus iconSta[5][6];//当前状态
    Icons::IconsStatus iconInitSta[5][6];//初始状态
    Icons* icons[5][6];//视觉组件

    Icons* lastSelectedIcon;
    Icons* selectedIcon;

    int startAll;
    int startLeft;//从UserDefault中进行总星星数、剩余可用星星数的读取
    Label* lastStartLabel;

    //右侧面板UI
    Label* upNeedStartLabel;
    Label* iconNameLabel;
    Label* iconIntroductionLabel;
    Sprite* iconDisplay;
    Sprite* buyButten;

    void showBuyBut(Icons* iconSelect);

    bool onIconTouchBegan(Touch* , Event* );
    void onTouchEnded(Touch* , Event* ) override;
    bool onBuyButTouchBegan(Touch* , Event* );
    void onBuyButTouchEnded(Touch* , Event* );
    bool onConfirmTouchBegan(Touch* touch,Event* event);
    void onConfirmTouchEnded(Touch* touch,Event* event);

    //重置为原始未升级状态
    bool resetSta(Touch* touch , Event* event);
    void resetStaEnded(Touch* , Event* );

    void onKeyReleased(EventKeyboard::KeyCode keycode, Event* event) override;//物理按键处理（适配安卓）
};
#endif //KINGDOMRUSH_STU_UPGRADES_H