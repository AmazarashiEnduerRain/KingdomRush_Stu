//
// Created by 20619 on 2025/11/18.
//
#include "TouchLayer.h"
#include "Data/GameManager.h"
#include "PlayerStateMenu.h"
#include "Bullet/FireBall.h"
#include "Map/BaseMap.h"
#include "Bullet/Dynamite.h"
#include "Soldier/ReinforceSoldier1.h"
#include "Soldier/ReinforceSoldier2.h"
#include "Bullet/Freeze.h"

bool TouchLayer::init(){
	if ( !Layer::init() ) return false;

	winSize = Director::getInstance()->getWinSize();

	Soldierlistener = NULL;
	Freezelistener = NULL;
	Dynamitelistener = NULL;
	FiereBalllistener = NULL;

	SpriteFrame* frame = NULL;
	Vector<SpriteFrame*> aFrames;//旗帜动画缓存
	for (int len = 1;len <= 30; len++){
		frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(__String::createWithFormat("rally_feedback_00%2d.png",len)->getCString());
		if(frame!=nullptr) aFrames.pushBack(frame);
	}
	AnimationCache::getInstance()->addAnimation(Animation::createWithSpriteFrames(aFrames, 0.04f),"rally_flag");

	isFlag = false;
	isMoved = false;

	setTouchShield();//开启基础触摸
	return true;
}

void TouchLayer::setTouchShield(){
	touchlistener = EventListenerTouchOneByOne::create();
	touchlistener->onTouchBegan = CC_CALLBACK_2(TouchLayer::onTouchBegan, this);
	touchlistener->onTouchEnded = CC_CALLBACK_2(TouchLayer::onTouchEnded, this);
	touchlistener->onTouchMoved = CC_CALLBACK_2(TouchLayer::onTouchMoved, this);
	touchlistener->setSwallowTouches(true);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchlistener,this);
}

void TouchLayer::removeTouchShield(){
	if(touchlistener != NULL) _eventDispatcher->removeEventListener(touchlistener);
}

bool TouchLayer::onTouchBegan(Touch* touch, Event* event){
	touchlistener->setSwallowTouches(false);
	return true;
}

void TouchLayer::onTouchEnded(Touch* touch, Event* event){
	touchlistener->setSwallowTouches(isMoved);//如果发生拖动，则吞噬（点击不到塔等）
	if(!isMoved){
		static_cast<BaseMap*>(this->getParent())->playerState->removeTowerInfo();
		static_cast<BaseMap*>(this->getParent())->playerState->removeMonsterInfo();
	}
	isMoved = false;
}

void TouchLayer::onTouchMoved(Touch* touch, Event* event){
	// 计算滑动过程中的滑动增量
	auto diff = touch->getDelta();
	if(abs(diff.x) > 5 || abs(diff.y) > 5){isMoved = true;} //手指移动修正，适配安卓

	auto currentPos = this->getParent()->getPosition();//移动父节点
	auto pos = currentPos + diff;

	//边界控制
	pos.x = MIN(pos.x, 0);
	pos.x = MAX(pos.x, -1200 + winSize.width);
	pos.y = MIN(pos.y, 0);
	pos.y = MAX(pos.y, -1000 + winSize.height);

	this->getParent()->setPosition(pos);
}

void TouchLayer::setFireBallTouchShield(){
	FiereBalllistener = EventListenerTouchOneByOne::create();
	FiereBalllistener->onTouchBegan = CC_CALLBACK_2(TouchLayer::onFireBallTouchBegan, this);
	FiereBalllistener->onTouchEnded = CC_CALLBACK_2(TouchLayer::onFireBallTouchEnded, this);
	FiereBalllistener->setSwallowTouches(true);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(FiereBalllistener,this);//优先级设置要确保高于普通触摸
}

void TouchLayer::removeFireBallTouchShield(){
	if(FiereBalllistener != NULL) _eventDispatcher->removeEventListener(FiereBalllistener);
}

bool TouchLayer::onFireBallTouchBegan(Touch* touch, Event* event){
	return true;
}

void TouchLayer::onFireBallTouchEnded(Touch* touch, Event* event){
	SoundManager::playFireballUnleash();
	//创建3个陨石
	auto fireBall1 = FireBall::create();
	addChild(fireBall1);
	fireBall1->shoot(static_cast<TouchLayer*>(event->getCurrentTarget())->convertTouchToNodeSpace(touch) + Point(-30,300));
	auto fireBall2 = FireBall::create();
	addChild(fireBall2);
	fireBall2->shoot(static_cast<TouchLayer*>(event->getCurrentTarget())->convertTouchToNodeSpace(touch) + Point(0,350));
	auto fireBall3 = FireBall::create();
	addChild(fireBall3);
	fireBall3->shoot(static_cast<TouchLayer*>(event->getCurrentTarget())->convertTouchToNodeSpace(touch) + Point(30,280));

	static_cast<BaseMap*>(this->getParent())->playerState->startStone();//通知UI层重新开始冷却计时
	removeFireBallTouchShield();
}

void TouchLayer::setDynamiteTouchShield(){
	Dynamitelistener = EventListenerTouchOneByOne::create();
	Dynamitelistener->onTouchBegan = CC_CALLBACK_2(TouchLayer::onDynamiteTouchBegan, this);
	Dynamitelistener->onTouchEnded = CC_CALLBACK_2(TouchLayer::onDynamiteTouchEnded, this);
	Dynamitelistener->setSwallowTouches(true);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(Dynamitelistener,this);
}

void TouchLayer::removeDynamiteTouchShield(){
	if(Dynamitelistener != NULL) _eventDispatcher->removeEventListener(Dynamitelistener);
}

bool TouchLayer::onDynamiteTouchBegan(Touch* touch, Event* event){
	return true;
}

void TouchLayer::onDynamiteTouchEnded(Touch* touch, Event* event){
	auto dynamite = Dynamite::create();
	this->getParent()->addChild(dynamite);
	dynamite->shoot(static_cast<TouchLayer*>(event->getCurrentTarget())->convertTouchToNodeSpace(touch));
	removeDynamiteTouchShield();
}

void TouchLayer::setFreezeTouchShield(){
	Freezelistener = EventListenerTouchOneByOne::create();
	Freezelistener->onTouchBegan = CC_CALLBACK_2(TouchLayer::onFreezeTouchBegan, this);
	Freezelistener->onTouchEnded = CC_CALLBACK_2(TouchLayer::onFreezeTouchEnded, this);
	Freezelistener->setSwallowTouches(true);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(Freezelistener,this);
}

void TouchLayer::removeFreezeTouchShield(){
	if(Freezelistener != NULL) _eventDispatcher->removeEventListener(Freezelistener);
}

bool TouchLayer::onFreezeTouchBegan(Touch* touch, Event* event){
	return true;
}

void TouchLayer::onFreezeTouchEnded(Touch* touch, Event* event){
	SoundManager::playFreeze();
	auto freeze = Freeze::create();
	this->getParent()->addChild(freeze);
	freeze->shoot(static_cast<TouchLayer*>(event->getCurrentTarget())->convertTouchToNodeSpace(touch));
	removeFreezeTouchShield();
}

void TouchLayer::setSoldierTouchShield(){
	Soldierlistener = EventListenerTouchOneByOne::create();
	Soldierlistener->onTouchBegan = CC_CALLBACK_2(TouchLayer::onSoldierTouchBegan, this);
	Soldierlistener->onTouchEnded = CC_CALLBACK_2(TouchLayer::onSoldierTouchEnded, this);
	Soldierlistener->setSwallowTouches(true);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(Soldierlistener,this);
}

void TouchLayer::removeSoldierTouchShield(){
	_eventDispatcher->removeEventListener(Soldierlistener);
}

bool TouchLayer::onSoldierTouchBegan(Touch* touch, Event* event){
	return true;
}

void TouchLayer::onSoldierTouchEnded(Touch* touch, Event* event){
	SoundManager::playReinforcement();
	auto target = static_cast<TouchLayer*>(event->getCurrentTarget());
	Point locationInNode = target->convertTouchToNodeSpace(touch);

	auto feedBack = Sprite::createWithSpriteFrameName("confirm_feedback_layer2_0001.png");//点击反馈动画
	feedBack->setPosition(locationInNode);
	addChild(feedBack);
	feedBack->runAction(Sequence::create(FadeOut::create(1.0f),
				CallFuncN::create(CC_CALLBACK_0(Sprite::removeFromParent, feedBack)),NULL));

	auto reinforceSoldier1 = ReinforceSoldier1::createReinforceSoldier(Point(locationInNode.x + 15,locationInNode.y + 20));
	this->getParent()->addChild(reinforceSoldier1);
	auto reinforceSoldier2 = ReinforceSoldier2::createReinforceSoldier(Point(locationInNode.x - 15,locationInNode.y + 20));
	this->getParent()->addChild(reinforceSoldier2);//援兵直接添加为地图的子节点

	static_cast<BaseMap*>(this->getParent())->playerState->startParatrooper();
	removeSoldierTouchShield();
}

void TouchLayer::setRallyFlagTouchShield(){
	rallyCircle = RallyCircle::create();
	rallyCircle->setPosition(tower->getParent()->getPosition());//圆的中心位置设置在塔的基座处
	rallyCircle->setTag(1001);
	addChild(rallyCircle);

	listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(TouchLayer::onRallyFlagTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(TouchLayer::onRallyFlagTouchEnded, this);
	listener->setSwallowTouches(true);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener,this);
}

void TouchLayer::removeRallyFlagTouchShield(){
	removeChildByTag(1001);
	if(listener != NULL) _eventDispatcher->removeEventListener(listener);
}

bool TouchLayer::onRallyFlagTouchBegan(Touch* touch, Event* event){
	auto target = static_cast<TouchLayer*>(event->getCurrentTarget());
	Point locationInNode = target->convertTouchToNodeSpace(touch);
	if(locationInNode.distance(tower->getParent()->getPosition()) < 180 && locationInNode.distance(tower->getParent()->getPosition()) > 40){
		addRallyFlag(locationInNode);
		tower->setRallyPoint(locationInNode);
		SoundManager::playRallyPointPlaced();
		isFlag = true;
	}else addWrongPlace(static_cast<TouchLayer*>(event->getCurrentTarget())->convertTouchToNodeSpace(touch));

	return true;
}

void TouchLayer::onRallyFlagTouchEnded(Touch* touch, Event* event){
	if(isFlag){
		removeRallyFlagTouchShield();
		isFlag = false;
	}
}

void TouchLayer::addRallyFlag(Point location){
	auto flag = Sprite::createWithSpriteFrameName("rally_feedback_0015.png");
	flag->setPosition(location);
	addChild(flag);
	flag->runAction(Sequence::create(Animate::create(AnimationCache::getInstance()->getAnimation("rally_flag"))
										,CallFuncN::create(CC_CALLBACK_0(Sprite::removeFromParent, flag)), NULL));
}

void TouchLayer::addWrongPlace(Point location){
	auto wrong = Sprite::createWithSpriteFrameName("error_feedback_0001.png");
	wrong->setPosition(location);
	wrong->runAction(Sequence::create(FadeOut::create(1.0f)
										,CallFuncN::create(CC_CALLBACK_0(Sprite::removeFromParent, wrong)), NULL));
	addChild(wrong);
}

void TouchLayer::removeAllListener(){
	removeFireBallTouchShield();
	removeFreezeTouchShield();
	removeSoldierTouchShield();
	removeRallyFlagTouchShield();
	removeDynamiteTouchShield();
}