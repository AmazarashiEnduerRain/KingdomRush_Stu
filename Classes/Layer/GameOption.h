//
// Created by 20619 on 2025/11/17.
// 暂停/设置菜单（游戏时右上角可点开的菜单）

#ifndef KINGDOMRUSH_STU_GAMEOPTION_H
#define KINGDOMRUSH_STU_GAMEOPTION_H

#include "cocos2d.h"
USING_NS_CC;

class GameOption : public Layer{
public:
    bool init() override;
    CREATE_FUNC(GameOption);
    int difficult;
    int level;
private:
    void initOption();//负责背景绘制
    void initButton();//负责按钮创建与绑定
    void pauseGame();
    Sprite* option;
    bool onTouchBegan(Touch* touch, Event* event) override;
    void onTouchEnded(Touch* touch, Event* event) override;
    void addOff(Sprite* target);//给音乐/音效图标添加禁用标志
    void onKeyReleased(EventKeyboard::KeyCode keycode, Event* event) override;//监听安卓返回键。cocos2d可在多平台运行
};
#endif //KINGDOMRUSH_STU_GAMEOPTION_H