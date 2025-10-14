//
// Created by 20619 on 2025/10/14.
//

#ifndef KINGDOMRUSH_STU_BASESOLDIER_H
#define KINGDOMRUSH_STU_BASESOLDIER_H

#include "Data/SoundManager.h"
#include "Monster/BaseMonster.h"
#include "cocos2d.h"
USING_NS_CC;

typedef enum{
    SoldierStateNone = 0, //无状态
    SoldierStateRun,//行走
    SoldierStateHit, //攻击
    SoldierStateDeath,//死亡
    SoldierStateWait,//寻找敌人
    SoldierStateSkill1,
    SoldierStateSkill2 //为技能预留的状态
}SoldierState;

class BaseSoldier : public Sprite
{
public:
    CC_SYNTHESIZE(float, maxHp, MaxHp);
    CC_SYNTHESIZE(float, currHp, CurrHp);
    CC_SYNTHESIZE(float, force, Force);
    CC_SYNTHESIZE(float, armor, Armor);
    CC_SYNTHESIZE(float, hpPercentage, HpPercentage);
    CC_SYNTHESIZE(SoldierState, state, State);
    CC_SYNTHESIZE_READONLY(ProgressTimer*, hpBar, HpBar);
    CC_SYNTHESIZE(Point, location, Location);
    Sprite* baseSprite;
    BaseMonster* nearestMonster;

    virtual void runToLocation(Point point);
    bool init() override;
    virtual void updateSoldier(int level){};
protected:
    virtual void createAndSetHpBar();
    Sprite* hpBgSprite;
    virtual void lookingForMonsters(float dt);

    virtual void checkNearestMonster();
    virtual void attack();
    void update(float dt) override {};

    virtual void runToDestination(Point destination,bool isAttacking){};
    SoldierState lastState;
    virtual void stopSoldierAnimation();
    void checkDirection(Point point);
    //false右边；true左边
    virtual bool checkDirectionForMonster();
    float caculateTime(Point point);
    virtual void runToMonster();
    virtual void attackMonster(float dt){};
    int attackCount;
};


#endif //KINGDOMRUSH_STU_BASESOLDIER_H