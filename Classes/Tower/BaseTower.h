#ifndef __BASE_TOWER_H__
#define __BASE_TOWER_H__

#include "cocos2d.h"

class CustomTerrain;
class BaseMonster;

USING_NS_CC;

typedef enum{
    ARCHER_1 = 0, //1级箭塔
    ARCHER_2, //2级箭塔
    ARCHER_3, //3级箭塔
    COSSBOW, //弩塔
    TOTEMTOWER, //野人
    ARTILLERY_1,//1级炮塔
    ARTILLERY_2,//2级炮塔
    ARTILLERY_3,//3级炮塔
    EARTHQUAKE, //地震
    MECHS, //机器
    BARAACKS_1,//1级兵营
    BARAACKS_2,//2级兵营
    BARAACKS_3,//3级兵营
    ASSASSIN,//盗贼
    TEMPLAR,//战士
    MAGE_1,//1级法师塔
    MAGE_2,//2级法师塔
    MAGE_3,//3级法师塔
    ARCHMAGE,//龙卷风
    NEC,//死灵法师
}TowerType;

class BaseTower: public Sprite {
public:
    BaseTower();
    ~BaseTower();

    virtual bool init() override;

    virtual void updateTower() {}
    virtual void update1(){}
    virtual void update2(){}
    virtual void setRallyPoint(Point point){}
    virtual void showUpdateMenu(){}

    void sellTower();
    void removeTower();
    void showTowerInfo();

    //使用CC_SYNTHESIZE宏自动生成getter和setter
    CC_SYNTHESIZE(TowerType, towerType, towerType);
    CC_SYNTHESIZE(CustomTerrain*, myTerrain, MyTerrain);
    CC_SYNTHESIZE(std::string, towerName, TowerName);
    CC_SYNTHESIZE(int, level, Level);
    CC_SYNTHESIZE(float, scope, Scope);
    CC_SYNTHESIZE(float, nextScope, NextScope);
    CC_SYNTHESIZE(float, rate, Rate);
    CC_SYNTHESIZE(int, force, Force);
    CC_SYNTHESIZE(int, updateMoney, UpdateMoney);
    CC_SYNTHESIZE(int, buildMoney, BuildMoney);

    bool isUpdateMenuShown;

protected:
    void setListener();
    void hideUpdateMenu();
    virtual void checkNearestMonster();

    bool onTouchBegan(Touch *touch, Event *event);
    void onTouchEnded(Touch* touch, Event *event);

    BaseMonster* nearestMonster; //用于索敌
    Sprite* terrain; //用于绑定触摸事件
};

#endif