//
// Created by 20619 on 2025/10/25.
//

#ifndef KINGDOMRUSH_STU_BASEBARRACKSTOWER_H
#define KINGDOMRUSH_STU_BASEBARRACKSTOWER_H

#include "cocos2d.h"
#include "BaseTower.h"
#include "Soldier/BaseSoldier.h"

USING_NS_CC;

class BaseBarracksTower : public BaseTower{
public:
    bool init() override; //重写初始化
    void updateTower() override; //重写升级方法
    void showUpdateMenu() override; //重写显示升级菜单方法
    CREATE_FUNC(BaseBarracksTower);

    void buildingAnimation();//播放建造动画
    void setRallyPoint(Point location) override;//重写设置集结点方法
    void update1() override;
    void update2() override;//升级路径1、2
    void sellTower() override;//重写出售塔方法
private:
    void buildingSmokeAnimation(float dt);//建造时的烟雾效果
protected:
    void initTower();
    void addTerrain();

    Sprite* towerBase;
    Sprite* door;//兵营门精灵（播放出兵动画）
    Vector<BaseSoldier*> Soldiers;
    void cureSoldiers(float dt);//周期性检查士兵状态（治疗/复活）
    void initSoldierLocation();
};


#endif //KINGDOMRUSH_STU_BASEBARRACKSTOWER_H