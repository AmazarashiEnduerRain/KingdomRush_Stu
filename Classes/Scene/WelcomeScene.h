//
// Created by 20619 on 2025/11/19.
// 在加载界面结束后呈现的主菜单界面

#ifndef KINGDOMRUSH_STU_WELCOMESCENE_H
#define KINGDOMRUSH_STU_WELCOMESCENE_H

#include "cocos2d.h"
USING_NS_CC;

class WelcomeScene : public Layer{
public:
    static cocos2d::Scene* createScene();
    bool init() override;
    CREATE_FUNC(WelcomeScene);

    //一系列组件的初始化
    void initBackGround();//背景图
    void initLogo();//Logo
    void initButton_start();//开始按钮
    void init_creditBtn();//制作人员名单按钮
    void initSoundButton();//音效、音乐按钮
    void initMenu_save();//存档菜单

    //交互回调
    void savemenuCloseCallback(cocos2d::Ref* pSender);
    void setSaveMenuInVisible();
    void setSaveMenuVisible();

    //动画相关函数
    void initLogoAnimation();//Logo动画
    void initButton_startAnimation();
    void init_creditBtn_startAnimation();

    void onKeyReleased(EventKeyboard::KeyCode keycode, Event* event) override;//物理按键回调
    void onEnterTransitionDidFinish() override;//进场动画回调
private:
    Size visibleSize;

    Point point_Logo;
    Sprite *sprite_Logo;

    Sprite *button_Start;
    Sprite *button_credit;

    Sprite *menu_Save;
    Point point_Menu_Save;//存档菜单位置
    MenuItemSprite *button_Menu_Save_Close;
    Point point_Button_Menu_Save_Close;//关闭存档菜单按钮位置
};


#endif //KINGDOMRUSH_STU_WELCOMESCENE_H