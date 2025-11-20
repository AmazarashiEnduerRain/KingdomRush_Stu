//
// Created by 20619 on 2025/11/19.
// 商店场景

#ifndef KINGDOMRUSH_STU_SHOPSCENE_H
#define KINGDOMRUSH_STU_SHOPSCENE_H

#include "cocos2d.h"
#include "Sprite/ShopIcon.h"
USING_NS_CC;

class ShopScene : public Layer{
public:
    static Scene* createScene();
    bool init() override;
    CREATE_FUNC(ShopScene);
protected:
    Size size;

    //右侧黑板上的文字控件
    Label *label;//名称
    Label *label2;//价格
    Label *label3;//简介
    Label *gemLabel;//剩余宝石数

    void onKeyReleased(EventKeyboard::KeyCode keycode, Event* event) override;

    int count[6];//道具持有的数量
    int gem;//宝石的数量

    Vector<Sprite*> backpackIcons;
    Vector<ShopIcon*> shopIcons;
    Vector<Label*> countLabels;

    //字符串数据源：简介、名称、价格等
    std::string str_introduction[6];
    std::string str_name[6];
    int str_gem[6];

    Sprite* board;//右侧黑板

    void setBoard(int type);//更新黑板显示内容
    void initPicture();//界面初始化
    void initBackpackIcon();//初始化左侧背包栏
    void setBackpackIcon(int type);//更新背包图标
    void buySth(int i);//执行购买逻辑
};


#endif //KINGDOMRUSH_STU_SHOPSCENE_H