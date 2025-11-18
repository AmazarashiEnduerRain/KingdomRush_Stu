//
// Created by 20619 on 2025/11/18.
// 升级界面的主要组件

#ifndef KINGDOMRUSH_STU_ICONS_H
#define KINGDOMRUSH_STU_ICONS_H

#include "cocos2d.h"
USING_NS_CC;

class Icons: public Sprite{
public :
    //设置三种状态：不可升级，可升级，已升级
    enum IconsStatus{eIconOff,eIconOn,eIconOK};

    virtual bool initNewIcons(std::string picture,std::string off_picture,std::string iconName,
        std::string iconIntroduction,int startNum,Icons::IconsStatus iconSta,int row,int column);
    static Icons* createNewIcons(std::string picture,std::string off_picture,std::string iconName,
        std::string iconIntroduction,int startNum,Icons::IconsStatus iconSta,int row,int column);
    CREATE_FUNC(Icons);

    void showIcon(Icons::IconsStatus iconSta);//IconSta用于修改图标状态

    int priceTag;//升级所需的星星数
    Sprite* icon;//技能图标
    Sprite* iconSelected;//选中时的高亮边框

    void iconIsSelect(bool select);
    std::string iconName;//名称
    std::string iconIntroduction;//介绍

    int iconRow;
    int	iconColumn;

    IconsStatus getIconState();
    void setMayUpdate();
    void setUpdated();
protected:
    IconsStatus iconSta;//当前图标的状态
    Sprite* iconOKBack;//升级后显示的图标
    std::string picture;
    std::string off_picture;
};
#endif //KINGDOMRUSH_STU_ICONS_H