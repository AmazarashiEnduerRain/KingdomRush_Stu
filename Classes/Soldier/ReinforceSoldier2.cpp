//
// Created by 20619 on 2025/11/5.
//

#include "ReinforceSoldier2.h"
#include "Data/GameManager.h"

ReinforceSoldier2* ReinforceSoldier2::createReinforceSoldier(Point point){
    auto reinforceSoldier = new ReinforceSoldier2();
    if (reinforceSoldier && reinforceSoldier->init()){
        reinforceSoldier->setLocation(point);
		reinforceSoldier->setMaxHp(80);
		reinforceSoldier->setCurrHp(80);
		reinforceSoldier->setForce(10);
		reinforceSoldier->setState(SoldierStateNone);
		reinforceSoldier->birth(point);
        reinforceSoldier->autorelease();
        return reinforceSoldier;
    }
	CC_SAFE_DELETE(reinforceSoldier);
    return NULL;
}

void ReinforceSoldier2::birth(Point point){
	setPosition(point);
	scheduleUpdate();
	schedule(schedule_selector(ReinforceSoldier2::lookingForMonsters), 1.0f,-1,caculateTime(point));
}

bool ReinforceSoldier2::init(){
	if(!BaseSoldier::init()) return false;

	baseSprite = Sprite::createWithSpriteFrameName("reinforce_B0_0001.png");
	addChild(baseSprite);
	createAndSetHpBar();
	lastState = SoldierStateNone;

	return true;
}

void ReinforceSoldier2::attackMonster(float dt){
	if(nearestMonster != NULL && nearestMonster->getCurrHp() > 0){
		if (!checkDirectionForMonster()) nearestMonster->setState(stateAttackLeft);
		else nearestMonster->setState(stateAttackRight);

		setState(SoldierStateHit);
		auto monsterCurrHp = nearestMonster->getCurrHp();
		auto SoldierHp = this->getCurrHp();

		monsterCurrHp =  monsterCurrHp - this->getForce();

		if(nearestMonster->getState() != stateFrozen)
			SoldierHp =  SoldierHp - nearestMonster->getForce();

		if(monsterCurrHp <= 0) monsterCurrHp = 0;
		if(SoldierHp <= 0) SoldierHp = 0;
		nearestMonster->setCurrHp( monsterCurrHp );
		this->setCurrHp(SoldierHp);

		nearestMonster->getHpBar()->setPercentage((monsterCurrHp/nearestMonster->getMaxHp()) * 100);
		this->getHpBar()->setPercentage((SoldierHp/this->getMaxHp()) * 100);

		if(monsterCurrHp == 0){
			unschedule(schedule_selector(ReinforceSoldier2::attackMonster));
			nearestMonster->death();
			if(this->getCurrHp() > 0) runToLocation(location);
		}
		if(SoldierHp == 0){
			lastState = SoldierStateDeath;
			setState(SoldierStateDeath);
			unscheduleAllCallbacks();
			stopAllActions();
			baseSprite->stopAllActions();
			hpBgSprite->setVisible(false);
			if(nearestMonster != NULL && nearestMonster->getCurrHp() > 0){
				nearestMonster->restartWalking();
				nearestMonster->setIsAttacking(false);
			}
			baseSprite->runAction(Sequence::create(FadeOut::create(1.0f)
			,CallFuncN::create(CC_CALLBACK_0(ReinforceSoldier2::removeFromParent, this)),NULL));
		}
	}else{
		unschedule(schedule_selector(ReinforceSoldier2::attackMonster));
		if(this->getCurrHp() > 0) runToLocation(location);
	}
}

void ReinforceSoldier2::update(float dt){
	//若状态更新
	if(lastState!=getState()){
		//根据状态判断
		switch (getState()){
		case(SoldierStateRun):{
			lastState = SoldierStateRun;
			//停止之前动画
			stopSoldierAnimation();
			auto action = RepeatForever::create(Animate::create(AnimationCache::getInstance()->getAnimation("reinforce2_run")));
			action->setTag(SoldierStateRun);
			baseSprite->runAction(action);}
			break;
		case(SoldierStateHit):{
			lastState = SoldierStateHit;
			stopSoldierAnimation();
			auto action = RepeatForever::create(Animate::create(AnimationCache::getInstance()->getAnimation("reinforce2_attack")));
			action->setTag(SoldierStateHit);
			baseSprite->runAction(action);}
			break;
		case(SoldierStateWait):{
			lastState = SoldierStateWait;
			stopSoldierAnimation();
			baseSprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("reinforce_B0_0001.png"));}
			break;
		}
	}
}

void ReinforceSoldier2::checkNearestMonster(){
	auto instance = GameManager::getInstance();
    auto monsterVector = instance->monsterVector;
    nearestMonster = NULL;
	for(int i = 0; i < monsterVector.size(); i++){
		auto monster = monsterVector.at(i);
		double distance = (this->getPosition()).getDistance(monster->baseSprite->getPosition());

		if (monster->getAttackBySoldier() && distance < 50 && (!monster->getIsAttacking())) {
            nearestMonster = monster;
			nearestMonster->stopWalking();
			nearestMonster->setIsAttacking(true);
			break;
		}
	}
}

void ReinforceSoldier2::runToMonster(){
	Point destination;
	if (!checkDirectionForMonster()){//怪在右边
		destination.x = nearestMonster->baseSprite->getPositionX() + nearestMonster->baseSprite->getContentSize().width/2 - this->baseSprite->getContentSize().width / 2;
		destination.y = nearestMonster->baseSprite->getPositionY() - this->baseSprite->getContentSize().height / 4;
	}else{//左边
		destination.x = nearestMonster->baseSprite->getPositionX() - nearestMonster->baseSprite->getContentSize().width/2 + this->baseSprite->getContentSize().width / 2;
		destination.y = nearestMonster->baseSprite->getPositionY() - this->baseSprite->getContentSize().height / 4;
	}
	setState(SoldierStateRun);
	runAction(Sequence::create(MoveTo::create(caculateTime(destination),destination) , NULL));
	schedule(schedule_selector(ReinforceSoldier2::attackMonster), 1.0f,-1,caculateTime(destination));
}

bool ReinforceSoldier2::checkDirectionForMonster(){
	if((nearestMonster->baseSprite->getPositionX() - this->getPositionX()) > 0) {
		baseSprite->setFlippedX(false);
		return false;
	}
	baseSprite->setFlippedX(true);
	return true;
}