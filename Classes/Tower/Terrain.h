//
// Created by 20619 on 2025/11/7.
//

#ifndef KINGDOMRUSH_STU_TERRAIN_H
#define KINGDOMRUSH_STU_TERRAIN_H

#include "cocos2d.h"
USING_NS_CC;
class CustomTerrain : public Sprite{
public:
    virtual bool init(int type);//根据传入类型进行初始化（荒野、丛林等）
    static CustomTerrain* createTerrain(int type);

    void showUpdateMenu();
    void hideUpdateMenu();

    Sprite* terrain;//实际呈现地形贴图

    //触摸事件处理
    bool onTouchBegan(Touch *touch, Event *event);
    void onTouchEnded(Touch* touch, Event* event);

    //标记菜单是否已经显示
    bool isUpdateMenuShown;

    //显示烟雾效果
    void smokeEffect();
};


#endif //KINGDOMRUSH_STU_TERRAIN_H