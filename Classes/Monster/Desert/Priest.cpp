#include "Priest.h"

USING_NS_CC;

Priest* Priest::createMonster(std::vector<Point> points){
    auto monster = new Priest();
    if (monster && monster->init()){
        monster->setPointsVector(points);
        monster->setMaxHp(480);
        monster->setCurrHp(480);
        monster->setMoney(50);
        monster->setRunSpeed(35);
        monster->setArmor(0);
        monster->setForce(30);
        monster->setAttackBySoldier(true);

        monster->runNextPoint();
        monster->autorelease();
        return monster;
    }
    CC_SAFE_DELETE(monster);
    return NULL;
}

bool Priest::init(){
    if (!Sprite::init()) return false;
    setMonsterType(PRIEST);
    setName("Priest_");
    baseSprite = Sprite::createWithSpriteFrameName("CanibalShamanPriest_0001.png");
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