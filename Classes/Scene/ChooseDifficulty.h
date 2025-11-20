//
// Created by 20619 on 2025/11/19.
// 关卡难度选择界面

#ifndef KINGDOMRUSH_STU_CHOOSEDIFFICULTY_H
#define KINGDOMRUSH_STU_CHOOSEDIFFICULTY_H

#include "cocos2d.h"
USING_NS_CC;

class ChooseDifficulty : public Layer{
public:
    static Scene* createSceneWithLevel(int level);
    bool init() override;
    CREATE_FUNC(ChooseDifficulty);

    //交互回调
    void menuCallback(Ref* pSpender);  //关闭按钮返回上一场景
    void menuCallnext(Ref* pSpender);  //开始战斗按钮进入下一场景

    //难度选择回调
    void starMenuCallback1(Ref* pSpender);
    void starMenuCallback2(Ref* pSpender);
    void starMenuCallback3(Ref* pSpender);

    int level;
    int difficulty;
    void initWithLevel(int level);//加载特定关卡数据
    void setBadges(int star);//根据获得的星星数量设置徽章显示
protected:
    void onKeyReleased(EventKeyboard::KeyCode keycode, Event* event) override;
    MenuItemToggle *toggleItem1; //挑战按钮
    MenuItemToggle *toggleItem2; //英雄模式按钮
    MenuItemToggle *toggleItem3; //钢铁模式按钮

    std::string blueStrTop;
    Label *blueLabel;
    Label *blackLabel;
    std::string blueStr[3];//三种模式下的不同标题
    std::string blackStr[3]; //三种模式下的不同介绍正文

    Sprite* star1;
    Sprite* star2;
    Sprite* star3;
    Sprite* star4;
    Sprite* star5;

    Size visibleSize;
};


#endif //KINGDOMRUSH_STU_CHOOSEDIFFICULTY_H