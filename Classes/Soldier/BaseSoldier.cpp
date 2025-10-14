//
// Created by 20619 on 2025/10/14.
//

#include "BaseSoldier.h"

void BaseSoldier::createAndSetHpBar(){
    hpBgSprite = Sprite::createWithSpriteFrameName("lifebar_bg_small.png");
	//hpBgSprite为血条背景图，hpBar为血条进度
    hpBgSprite->setPosition(Point(baseSprite->getContentSize().width / 2, baseSprite->getContentSize().height /3*2));
    baseSprite->addChild(hpBgSprite);

	hpBar = ProgressTimer::create(Sprite::createWithSpriteFrameName("lifebar_small.png"));
	hpBar->setType(ProgressTimer::Type::BAR);
	hpBar->setMidpoint(Point(0, 0.5f));
	hpBar->setBarChangeRate(Point(1, 0));
	hpBar->setPercentage(100);
    hpBar->setPosition(Point(hpBgSprite->getContentSize().width / 2, hpBgSprite->getContentSize().height / 2 ));
    hpBgSprite->addChild(hpBar);
}

void BaseSoldier::runToMonster(){
	Point destination;
	//计算目标点x、y坐标的逻辑为转换至防御塔坐标系
	if (!checkDirectionForMonster()){//怪在右边
		destination.x = nearestMonster->baseSprite->getPositionX() + nearestMonster->baseSprite->getContentSize().width/2
		- this->getParent()->getParent()->getPositionX()- this->baseSprite->getContentSize().width/2;
		destination.y = nearestMonster->baseSprite->getPositionY() - this->getParent()->getParent()->getPositionY()
		- this->baseSprite->getContentSize().height/4;
	}else{//左边
		destination.x = nearestMonster->baseSprite->getPositionX() - nearestMonster->baseSprite->getContentSize().width/2
		- this->getParent()->getParent()->getPositionX()+ this->baseSprite->getContentSize().width/2;
		destination.y = nearestMonster->baseSprite->getPositionY()- this->getParent()->getParent()->getPositionY()
		- this->baseSprite->getContentSize().height/4;
	}
	setState(SoldierStateRun);
	runAction(Sequence::create(MoveTo::create(caculateTime(destination),destination) , NULL));
	schedule(schedule_selector(BaseSoldier::attackMonster), 1.0f,-1,caculateTime(destination));
}

void BaseSoldier::runToLocation(Point point){
	if(getState() != stateDeath){
		unscheduleAllCallbacks();//重置状态。停止所有计划中的动作和任务
		scheduleUpdate(); //重启update循环
		stopAllActions();
		if((point.x - this->getPositionX())>0) baseSprite->setFlippedX(false);//右边
		else baseSprite->setFlippedX(true);

		setState(SoldierStateRun);
		runAction(Sequence::create(MoveTo::create(caculateTime(point),point),
		CallFuncN::create(CC_CALLBACK_0(BaseSoldier::setState, this,SoldierStateWait)),NULL));
		schedule(schedule_selector(BaseSoldier::lookingForMonsters), 1.0f,-1,caculateTime(point));
	}
}

bool BaseSoldier::init(){
	if (!Sprite::init()) return false;

	nearestMonster = nullptr;
	return true;
}

void BaseSoldier::lookingForMonsters(float dt){
	setState(SoldierStateWait);
	baseSprite->setFlippedX(!(baseSprite->isFlippedX()));//身体左右反转以做出四处张望的视觉效果
	checkNearestMonster();
	if(nearestMonster != nullptr && nearestMonster->getCurrHp() > 0) attack();
}

void BaseSoldier::checkNearestMonster(){
	auto instance = GameManager::getInstance();
    auto monsterVector = instance->monsterVector;
    nearestMonster = nullptr;
	for(int i = 0; i < monsterVector.size(); i++){
		auto monster = monsterVector.at(i);
		double distance = (this->getParent()->getParent()->getPosition()
			+ this->getPosition()).getDistance(monster->baseSprite->getPosition());
		//this->getPosition()得到士兵相对于父节点（防御塔）的坐标；this->getParent->getParent()->getPosition()得到防御塔的世界坐标

		if (monster->getAttackBySoldier() && distance < 50 && (!monster->getIsAttacking())) {
            nearestMonster = monster;
			nearestMonster->stopWalking();
			nearestMonster->setIsAttacking(true);
			break;
		}
	}
}

bool BaseSoldier::checkDirectionForMonster(){
	if((nearestMonster->baseSprite->getPositionX() - (this->getParent()->getParent()->getPositionX() + this->getPositionX()))>0){
		baseSprite->setFlippedX(false);
		return false;
	}else{
		baseSprite->setFlippedX(true);
		return true;
	}
}

float BaseSoldier::caculateTime(Point point){ return point.getDistance(this->getPosition())/100; }

void BaseSoldier::stopSoldierAnimation(){
	for(int i = 1 ;i <= 8;i++) baseSprite->stopActionByTag(i);
}

void BaseSoldier::attack() {
	unschedule(schedule_selector(BaseSoldier::lookingForMonsters));
	runToMonster();
}