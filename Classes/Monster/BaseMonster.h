//
// Created by 20619 on 2025/10/12.
//

#ifndef KINGDOMRUSH_STU_BASEMONSTER_H
#define KINGDOMRUSH_STU_BASEMONSTER_H

#include "cocos2d.h"
USING_NS_CC;

typedef enum {
    stateNone = 0,//无状态
    stateWalkRight,//向右走
    stateWalkLeft,//向左走
    stateWalkUp,//向上走
    stateWalkDown,//向下走
    stateAttackLeft,
    stateAttackRight,//攻击
    stateDeath,//死亡
    stateFrozen
}MonsterState;

typedef enum {
    THUG = 0,
    FALLEN,
    IMMORTAL,
    MUNRA,
    RAIDER,
    SCORPION,
    TREMOR,
    WASPHORNET,
    WASPQUEEN,
    WOLF,
    BOSS_EFREETI,
    EFREETI,
    CANIBAL,
    GORILLA,
    HUNTER,
    PRIEST,
    SHAMAN,
    SHIELD,
    WINGRIDER,
    BOSS_CANIBAL,
    CANIBAL_OFFSPRING,
    BLAZEFANG,
    BROODGUARD,
    ELITE,
    MYRMIDON,
    NIGHTSCALE,
    QUETZAL
}MonsterName;

class BaseMonster : public Sprite {
public:
    BaseMonster();
    ~BaseMonster();
    virtual bool init() override;
    CREATE_FUNC(BaseMonster);
    Sprite* baseSprite;
    virtual void getHurt();//冒血
    virtual void death();//躺着死
    virtual void explosion();//被炸死

    CC_SYNTHESIZE(std::vector<Point>, pointsVector, PointsVector);
    CC_SYNTHESIZE(bool, attackBySoldier, AttackBySoldier);
    CC_SYNTHESIZE(MonsterName, monsterType, MonsterType);
    CC_SYNTHESIZE(bool, attackByTower, AttackByTower);
    CC_SYNTHESIZE(bool, isAttacking, IsAttacking);
    CC_SYNTHESIZE(float, runSpeed, RunSpeed);
    CC_SYNTHESIZE(float, maxHp, MaxHp);
    CC_SYNTHESIZE(float, currHp, CurrHp);
    CC_SYNTHESIZE(float, force, Force);
    CC_SYNTHESIZE(float, armor, Armor);
    CC_SYNTHESIZE(float, hpPercentage, HpPercentage);
    CC_SYNTHESIZE(MonsterState, state, State);
    CC_SYNTHESIZE(int, money, Money);
    CC_SYNTHESIZE_READONLY(ProgressTimer*, hpBar, HpBar);

    virtual void stopWalking();
    virtual void restartWalking();
    virtual void slowRunSpeed(float dt, float dis);
    Point getNextPoint();
    virtual void frozen();
    virtual void refrozen(float dt);
protected:
    void setMonsterZorder(int yOrder);
    int pointCounter;
    Sprite* hpBgSprite;
    Point currPoint;
    Point nextPoint;
    Point tempNextPoint;
    void runNextPoint();
    void createAndSetHpBar();

    bool onTouchBegan(Touch* touch, Event* event);
    void onTouchEnded(Touch* touch, Event* event);

    void update(float dt) override;
    CC_SYNTHESIZE(bool, isSlowed, IsSlowed);

    Sprite* blood;
    MonsterState tempState;
    MonsterState lastState;
    void stopMonsterAnimation();
    Sprite* ice;
    void showInfo();
    void setListener();
};


#endif //KINGDOMRUSH_STU_BASEMONSTER_H