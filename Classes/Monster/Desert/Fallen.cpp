//
// Created by 20619 on 2025/11/4.
//

#include "Fallen.h"

USING_NS_CC;

Fallen* Fallen::createMonster(std::vector<Point> points){
    auto monster = new Fallen();
    if (monster && monster->init()){
        monster->setPointsVector(points);
		monster->setMaxHp(100);
		monster->setCurrHp(100);
		monster->setMoney(30);
		monster->setRunSpeed(30);
		monster->setArmor(0);
		monster->setAttackBySoldier(true);

    	monster->runNextPoint();
        monster->autorelease();
        return monster;
    }
    CC_SAFE_DELETE(monster);
    return NULL;
}

Fallen* Fallen::createMonster(std::vector<Point> points,Point birthLocation,int pointCounter){
    auto monster = new Fallen();
    if (monster && monster->init()){
        monster->setPointsVector(points);
		monster->setMaxHp(100);
		monster->setCurrHp(100);
		monster->setMoney(30);
		monster->setRunSpeed(30);
		monster->setArmor(0);

		monster->setAttackBySoldier(false);
		monster->setAttackByTower(false);
    	monster->birth(birthLocation,pointCounter);

        monster->autorelease();
        return monster;
    }
    CC_SAFE_DELETE(monster);
    return NULL;
}

void Fallen::birth(Point birthLocation,int pointCounter){
	baseSprite->setPosition(birthLocation);
	this->pointCounter = pointCounter;
	baseSprite->runAction(Sequence::create(
	Animate::create(AnimationCache::getInstance()->getAnimation(getName()+"birth")),
	CallFuncN::create(CC_CALLBACK_0(Fallen::setAttackBySoldier, this,true)),
	CallFuncN::create(CC_CALLBACK_0(Fallen::setAttackByTower, this,true)),
	CallFuncN::create(CC_CALLBACK_0(Fallen::runNextPoint, this)),
	NULL));
}

bool Fallen::init(){
	if (!Sprite::init()) return false;

	setMonsterType(FALLEN);
	setName("Fallen_");
	baseSprite = Sprite::createWithSpriteFrameName("fallen_0001.png");
	addChild(baseSprite);

	createAndSetHpBar();
	setState(stateNone);
	blood = Sprite::createWithSpriteFrameName("fx_blood_splat_red_0001.png");
	blood->setPosition(Point(baseSprite->getContentSize().width/2,baseSprite->getContentSize().height/2));
	baseSprite->addChild(blood);
	blood->setVisible(false);

	lastState = stateNone;
	scheduleUpdate();
	setListener();
	return true;
}