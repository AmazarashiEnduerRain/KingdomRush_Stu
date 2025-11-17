//
// Created by 20619 on 2025/11/9.
//

#include "Skeleton.h"
#include "Data/GameManager.h"

Skeleton* Skeleton::createSkeleton(Point point){
    auto skeleton = new Skeleton();
    if (skeleton && skeleton->init()){
        skeleton->setLocation(point);
		skeleton->setMaxHp(50);
		skeleton->setCurrHp(50);
		skeleton->setForce(5);
		skeleton->setState(SoldierStateNone);
		skeleton->birth(point);
        skeleton->autorelease();
        return skeleton;
    }
	CC_SAFE_DELETE(skeleton);
    return NULL;
}

void Skeleton::birth(Point point){
	setPosition(point);
	scheduleUpdate();
	baseSprite->runAction(Sequence::create(
		Animate::create(AnimationCache::getInstance()->getAnimation("skeleton_birth"))
		,CallFuncN::create(CC_CALLBACK_0(Skeleton::setState, this,SoldierStateWait)),NULL));
	schedule(schedule_selector(Skeleton::lookingForMonsters), 1.0f,-1,caculateTime(point));
}

bool Skeleton::init(){
	if(!BaseSoldier::init()) return false;

	baseSprite = Sprite::createWithSpriteFrameName("skeleton_0001.png");
	addChild(baseSprite);
	createAndSetHpBar();
	lastState = SoldierStateNone;

	return true;
}

void Skeleton::attackMonster(float dt){
	if(nearestMonster != NULL && nearestMonster->getCurrHp() > 0){
		if (!checkDirectionForMonster()) nearestMonster->setState(stateAttackLeft);
		else nearestMonster->setState(stateAttackRight);

		setState(SoldierStateHit);
		auto monsterCurrHp = nearestMonster->getCurrHp();
		auto SoldierHp = this->getCurrHp();

		monsterCurrHp =  monsterCurrHp - this->getForce();

		if(nearestMonster->getState() != stateFrozen) SoldierHp =  SoldierHp - nearestMonster->getForce();

		if(monsterCurrHp <= 0) monsterCurrHp = 0;
		if(SoldierHp <= 0) SoldierHp = 0;

		nearestMonster->setCurrHp( monsterCurrHp );
		this->setCurrHp(SoldierHp);

		nearestMonster->getHpBar()->setPercentage((monsterCurrHp/nearestMonster->getMaxHp()) * 100);
		this->getHpBar()->setPercentage((SoldierHp/this->getMaxHp()) * 100);

		if(monsterCurrHp == 0){
			unschedule(schedule_selector(Skeleton::attackMonster));
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
			if(nearestMonster != NULL && nearestMonster->getCurrHp()>0){
				nearestMonster->restartWalking();
				nearestMonster->setIsAttacking(false);
			}
			baseSprite->runAction(Sequence::create(
				Animate::create(AnimationCache::getInstance()->getAnimation("skeleton_death"))
				,FadeOut::create(1.0f)
				,CallFuncN::create(CC_CALLBACK_0(Skeleton::removeFromParent, this)),NULL));
		}
	}else{
		unschedule(schedule_selector(Skeleton::attackMonster));
		if(this->getCurrHp() > 0) runToLocation(location);
	}
}

void Skeleton::update(float dt){
	//若状态更新
	if(lastState != getState()){
		//根据状态判断
		switch (getState()){
		case(SoldierStateRun):{
			lastState = SoldierStateRun;
			//停止之前动画
			stopSoldierAnimation();
			auto action = RepeatForever::create(Animate::create(AnimationCache::getInstance()->getAnimation("skeleton_run")));
			action->setTag(SoldierStateRun);
			baseSprite->runAction(action);}
			break;
		case(SoldierStateHit):{
			lastState = SoldierStateHit;
			stopSoldierAnimation();
			auto action = RepeatForever::create(Animate::create(AnimationCache::getInstance()->getAnimation("skeleton_attack")));
			action->setTag(SoldierStateHit);
			baseSprite->runAction(action);}
			break;
		case(SoldierStateWait):{
			lastState = SoldierStateWait;
			stopSoldierAnimation();
			baseSprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("skeleton_0001.png"));}
			break;
		}
	}
}

void Skeleton::runToMonster(){
	Point destination;
	if (!checkDirectionForMonster()){//怪在右边
		destination.x = nearestMonster->baseSprite->getPositionX() + nearestMonster->baseSprite->getContentSize().width/2 - this->getParent()->getPositionX()- this->baseSprite->getContentSize().width/2;
		destination.y = nearestMonster->baseSprite->getPositionY() - this->getParent()->getPositionY() - this->baseSprite->getContentSize().height/4;
	}else{//左边
		destination.x = nearestMonster->baseSprite->getPositionX() - nearestMonster->baseSprite->getContentSize().width/2 - this->getParent()->getPositionX()+ this->baseSprite->getContentSize().width/2;
		destination.y = nearestMonster->baseSprite->getPositionY() - this->getParent()->getPositionY() - this->baseSprite->getContentSize().height/4;
	}
	setState(SoldierStateRun);
	runAction(Sequence::create(MoveTo::create(caculateTime(destination),destination) , NULL));
	schedule(schedule_selector(Skeleton::attackMonster), 1.0f,-1,caculateTime(destination));
}

void Skeleton::checkNearestMonster(){
	auto instance = GameManager::getInstance();
    auto monsterVector = instance->monsterVector;
    nearestMonster = NULL;
	for(int i = 0; i < monsterVector.size(); i++){
		auto monster = monsterVector.at(i);
		double distance = (this->getParent()->getPosition()+this->getPosition()).getDistance(monster->baseSprite->getPosition());

		if (monster->getAttackBySoldier() && distance < 50 && (!monster->getIsAttacking())) {
            nearestMonster = monster;
			nearestMonster->stopWalking();
			nearestMonster->setIsAttacking(true);
			break;
		}
	}
}

bool Skeleton::checkDirectionForMonster(){
	if((nearestMonster->baseSprite->getPositionX() - (this->getParent()->getPositionX() + this->getPositionX())) > 0){
		baseSprite->setFlippedX(false);
		return false;
	}
	baseSprite->setFlippedX(true);
	return true;
}

void Skeleton::createAndSetHpBar(){
    hpBgSprite = Sprite::createWithSpriteFrameName("lifebar_bg_small.png");

    hpBgSprite->setPosition(Point(baseSprite->getContentSize().width / 2, baseSprite->getContentSize().height));
    baseSprite->addChild(hpBgSprite);

	hpBar = ProgressTimer::create(Sprite::createWithSpriteFrameName("lifebar_small.png"));
	hpBar->setType(ProgressTimer::Type::BAR);
	hpBar->setMidpoint(Point(0, 0.5f));
	hpBar->setBarChangeRate(Point(1, 0));
	hpBar->setPercentage(100);
    hpBar->setPosition(Point(hpBgSprite->getContentSize().width / 2, hpBgSprite->getContentSize().height / 2 ));
    hpBgSprite->addChild(hpBar);
}