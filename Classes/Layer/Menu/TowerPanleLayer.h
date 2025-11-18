//
// Created by 20619 on 2025/11/17.
// 在空地上建造新的防御塔时调用

#ifndef KINGDOMRUSH_STU_TOWERPANLELAYER_H
#define KINGDOMRUSH_STU_TOWERPANLELAYER_H

#include "cocos2d.h"
#include "Sprite/Circle/Circle.h"
#include "Sprite/TowerIcon/BaseBuildIcon.h"
#include "Tower/Terrain.h"

USING_NS_CC;

class TowerPanleLayer: public Sprite{
public:
    virtual bool init() override;
    CREATE_FUNC(TowerPanleLayer);
    bool onTouchBegan(Touch *touch, Event *event);
    void onTouchEnded(Touch* touch, Event* event);
    CC_SYNTHESIZE(CustomTerrain*, terrain, MyTerrain); //绑定的地块对象，用于确定是哪一处地块唤起该菜单
    void inAnimation();
private:
    void addIcons();//初始化建筑图标
    void addTempTower(int type);//添加塔的预览（虚影与范围圆圈）
    void addTower(int type);//实际建造防御塔
    BaseBuildIcon* archerIcon;
    BaseBuildIcon* artilleryIcon;
    BaseBuildIcon* barracksIcon;
    BaseBuildIcon* magicIcon;

    Sprite* planeSprite;//背景圆环
    Circle* circle;
    Sprite *tempTower;
    bool isActionTaken;
};

#endif //KINGDOMRUSH_STU_TOWERPANLELAYER_H