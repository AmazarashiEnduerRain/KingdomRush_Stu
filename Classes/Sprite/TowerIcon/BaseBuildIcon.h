//
// Created by 20619 on 2025/11/13.
// 可点击图标的基类

#ifndef KINGDOMRUSH_STU_BASEBUILDICON_H
#define KINGDOMRUSH_STU_BASEBUILDICON_H

#include "cocos2d.h"

USING_NS_CC;

class BaseBuildIcon : public Sprite{
public:
    virtual bool initIcon(int type,int money);//使用type和money进行图标初始化（显示哪个图标、显示的价格）
    static BaseBuildIcon* createIcon(int type,int money);
    CREATE_FUNC(BaseBuildIcon);
    virtual void setSelected();
    virtual void setNotSelected();
    virtual void setNotEnoughMoney();
    virtual void setEnoughMoney();
    virtual void setUpdateMoney(int money);//修改图标价格
    Sprite* baseIcon;//图标的视觉精灵
protected:
    CC_SYNTHESIZE(bool, isAble, IsAble);//钱是否足够
    CC_SYNTHESIZE(int, type, Type);
    CC_SYNTHESIZE(bool, isSelected, IsSelected);
    CC_SYNTHESIZE(int, money, Money);//图标的显示价格
    void update(float dt) override;
    Sprite* okIcon;
    Sprite* priceIcon;//价格背景图
    Label* priceLabel;//价格文字标签
};
#endif //KINGDOMRUSH_STU_BASEBUILDICON_H