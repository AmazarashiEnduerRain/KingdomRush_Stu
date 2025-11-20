//
// Created by 20619 on 2025/11/20.
//

#ifndef KINGDOMRUSH_STU_ENCYCLOPEDIATIPS_H
#define KINGDOMRUSH_STU_ENCYCLOPEDIATIPS_H

#include "cocos2d.h"
USING_NS_CC;

class EncyclopediaTips : public Layer{
public:
    static Scene* createScene();
    bool init() override;
    CREATE_FUNC(EncyclopediaTips);

    void menuCallback(Ref *pSender); //切换场景（关闭按钮回调）
    void starMenuCallback1(Ref* pSender);
    void starMenuCallback2(Ref* pSender);
    void leftChange(Ref *pSender);
private :
     int currentIdx;//当前页码
    Label* contentLabel;//声明文字
    Label* pagNumLabel;//页码数字

    MenuItemSprite *btnLeft;//左翻页
    MenuItemSprite *btnRight;//右翻页

    std::string tipsString[30];//存储三十条信息的数组
};

#endif //KINGDOMRUSH_STU_ENCYCLOPEDIATIPS_H