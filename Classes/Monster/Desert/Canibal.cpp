#include "Canibal.h"

USING_NS_CC;

Canibal* Canibal::createMonster(std::vector<Point> points){
    auto monster = new Canibal();
    if (monster && monster->init()){
        monster->setPointsVector(points);
        monster->setMaxHp(200);
        monster->setCurrHp(200);
        monster->setMoney(10);
        monster->setRunSpeed(40);
        monster->setArmor(0);
        monster->setForce(15);
        monster->setAttackBySoldier(true);

        monster->runNextPoint();
        monster->autorelease();
        return monster;
    }
    CC_SAFE_DELETE(monster);
    return NULL;
}

bool Canibal::init(){
    if (!Sprite::init()) return false;
    setMonsterType(CANIBAL);
    setName("Canibal_");
    baseSprite = Sprite::createWithSpriteFrameName("Canibal_0001.png");
    addChild(baseSprite);

    createAndSetHpBar();
    blood = Sprite::createWithSpriteFrameName("fx_blood_splat_red_0001.png");
    blood->setPosition(Point(baseSprite->getContentSize().width/2,baseSprite->getContentSize().height/2));
    baseSprite->addChild(blood);
    blood->setVisible(false);

    lastState = stateNone;
    scheduleUpdate();
    setListener();
    return true;
}