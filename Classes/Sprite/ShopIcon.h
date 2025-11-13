//
// Created by 20619 on 2025/11/13.
// 商店场景中用来显示可购买道具的图标。其不继承于BaseBuildIcon(逻辑很大程度上不一致)

#ifndef KINGDOMRUSH_STU_SHOPICON_H
#define KINGDOMRUSH_STU_SHOPICON_H

#include "cocos2d.h"
USING_NS_CC;

class ShopIcon : public Sprite{
public:
    virtual bool initIcon(int tpye);
    CREATE_FUNC(ShopIcon);
    static ShopIcon* createIcon(int type);

    void setGlowing();
    void setNotGlowing();

    int type;
    Sprite* icon;//图标与光晕视觉精灵
    Sprite* glow;
};


#endif //KINGDOMRUSH_STU_SHOPICON_H