//
// Created by 20619 on 2025/11/20.
// 制作人员名单场景

#ifndef KINGDOMRUSH_STU_INFORMATION_H
#define KINGDOMRUSH_STU_INFORMATION_H

#include "cocos2d.h"
USING_NS_CC;
class Information : public cocos2d::CCLayer{
public:
    static Scene* createScene();
    bool init() override;
    CREATE_FUNC(Information);
    void initMap();//界面元素初始化

    void callBackMenu(Ref *pSpender);
};


#endif //KINGDOMRUSH_STU_INFORMATION_H