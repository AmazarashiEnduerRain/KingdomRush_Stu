//
// Created by 20619 on 2025/11/17.
//

#include "SimplePanleLayer.h"
#include "Data/GameManager.h"
USING_NS_CC;

bool SimplePanleLayer::init(){
    if (!Layer::init()) return false;

	isActionTaken = false;
	planeSprite = Sprite::createWithSpriteFrameName("gui_ring.png");
	planeSprite->setPosition(Point(0, 0));
	planeSprite->setScale(0.5f);
	addChild(planeSprite);

	sellIcon = SellIcon::create();
	sellIcon->setPosition(Point(0,-planeSprite->getContentSize().height / 2));
	sellIcon->setVisible(false);
	sellIcon->setTag(2);
	addChild(sellIcon);
	return true;
}

void SimplePanleLayer::inAnimation(){
	SoundManager::playTowerMenu();
	planeSprite->runAction(Sequence::create(ScaleTo::create(0.1f,1.0f,1.0f),
		CallFuncN::create(CC_CALLBACK_0(SimplePanleLayer::addIcons,this)),NULL));
}

void SimplePanleLayer::addIcons(){
	thisLvlCircle = Circle::create();

	thisLvlCircle->setScale(tower->getScope() / 160.0f);
	addChild(thisLvlCircle,-1);
	sellIcon->setVisible(true);
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->setSwallowTouches(true);
	touchListener->onTouchBegan = CC_CALLBACK_2(SimplePanleLayer::onTouchBegan, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(SimplePanleLayer::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, sellIcon);
}

bool SimplePanleLayer::onTouchBegan(Touch *touch, Event *event){
	auto target = static_cast<BaseBuildIcon*>(event->getCurrentTarget());
    Point locationInNode = target->convertTouchToNodeSpace(touch);
    Size size = target->baseIcon->getContentSize();
	Rect rect = Rect(0 - size.width / 2, 0 - size.height / 2, size.width, size.height);
    if (rect.containsPoint(locationInNode)){
		if(target->getIsSelected())//如果已经选中（第二次按下）
		{
			if(target->getIsAble())//如果钱够用
			{
				SoundManager::playTowerSell();
				GameManager::getInstance()->MONEY = GameManager::getInstance()->MONEY + (tower->getBuildMoney() / 2);
				tower->sellTower();
				this->setVisible(false);
				isActionTaken = true;
			}
		}else{//第一次按下
			target->setSelected();//设置为选中状态
		}
        return true;
    }
    return false;
}

void SimplePanleLayer::onTouchEnded(Touch* touch, Event* event){
	if(isActionTaken) removeFromParent();
}
