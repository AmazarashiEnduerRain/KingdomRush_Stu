//
// Created by 20619 on 2025/11/19.
//

#include "TransitionGame.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;
USING_NS_CC;

TransitionGame::TransitionGame(){m_FinishCnt = 0;}
TransitionGame::~TransitionGame(){}

TransitionGame * TransitionGame::create(float t, Scene *scene){
	TransitionGame *pScene = new TransitionGame();
    if (pScene && pScene->initWithDuration(t, scene)){
		pScene->autorelease();
        return pScene;
     }
     CC_SAFE_DELETE(pScene);
     return NULL;
}

TransitionGame * TransitionGame::createWithRenderTexture(float t, Scene *scene,RenderTexture *sqr){
	TransitionGame * pScene = new TransitionGame();
    if (pScene && pScene->initWithDuration(t, scene)){
		pScene->initRenderTexture(sqr);
		pScene->autorelease();
        return pScene;
     }
     CC_SAFE_DELETE(pScene);
     return NULL;
}

void TransitionGame::initRenderTexture(RenderTexture *sqr){
	auto _spr = Sprite::createWithTexture(sqr->getSprite()->getTexture());//将传入的渲染（截图）转换为精灵
    _spr->setPosition(Point(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 2));
	addChild(_spr);
}

void TransitionGame::onEnter(){
	TransitionScene::onEnter();

	_inScene->setVisible(false);//初始状态：新场景不可见
	Size visibleSize = Director::getInstance()->getVisibleSize();

	Point stLeftBegin, stLeftEnd, stRightBegin, stRightEnd;//定义关键坐标点
	stLeftBegin.setPoint(0,visibleSize.height / 2.0f);
	stLeftEnd.setPoint(visibleSize.width / 2.0f,visibleSize.height / 2.0f);
	stRightBegin.setPoint(visibleSize.width,visibleSize.height / 2.0f);
    stRightEnd.setPoint(visibleSize.width / 2.0f,visibleSize.height / 2.0f);

	auto pLeft = Sprite::createWithSpriteFrameName("transitionDoor.png");
	pLeft->setScaleX(visibleSize.width / 960);
	pLeft->setAnchorPoint(Point(1,0.5));
	pLeft->setPosition(stLeftBegin);
	addChild(pLeft,1);

	auto pRight = Sprite::createWithSpriteFrameName("transitionDoor.png");
	pRight->setScaleX(visibleSize.width / 960);
	pRight->setAnchorPoint(Point(0,0.5));
	pRight->setFlippedX(true);
	pRight->setPosition(stRightBegin);
	addChild(pRight,1);

	auto pLeft2 = Sprite::createWithSpriteFrameName("transitionLoading_left.png");
	pLeft2->setAnchorPoint(Point(1,0.5));
	pLeft2->setPosition(Point(pLeft->getContentSize().width,pLeft->getContentSize().height / 2));
	auto pRight2 = Sprite::createWithSpriteFrameName("transitionLoading_right.png");
	pRight2->setAnchorPoint(Point(0,0.5));
	pRight2->setPosition(Point(0,pRight->getContentSize().height / 2));

	pLeft->addChild(pLeft2);
	pRight->addChild(pRight2);

	//关门
	auto pActionLeft = MoveTo::create(_duration / 3, stLeftEnd);
    auto pActionRight = MoveTo::create(_duration / 3, stRightEnd);

	//停留
    auto pActionLeft1 = MoveTo::create(_duration / 3, stLeftEnd);
    auto pActionRight1 = MoveTo::create(_duration / 3, stRightEnd);

	//开门
    auto pActionLeft2 = MoveTo::create(_duration / 3, stLeftBegin);
    auto pActionRight2 = MoveTo::create(_duration / 3, stRightBegin);

	if(UserDefault::getInstance()->getIntegerForKey("backeffect",1) == 1){
		SimpleAudioEngine::getInstance()->playEffect("sound/GUITransitionOpen.wav");
	}
	pLeft->runAction(Sequence::create(
		pActionLeft,
		CallFuncN::create(CC_CALLBACK_0(TransitionGame::OnSencondActionFinish, this)),
		DelayTime::create(1.0f),
		pActionLeft2,
		CallFuncN::create(CC_CALLBACK_0(TransitionGame::LRFinish, this)),NULL));
	pRight->runAction(Sequence::create(
		pActionRight,
		DelayTime::create(1.0f),
		pActionRight2,NULL));
}

void TransitionGame::LRFinish(){TransitionScene::finish();} //转场结束。销毁过渡场景、outScene并将inScene设置为当前场景

void TransitionGame::OnSecondActionFinish(){
	//播放开门音效，影藏旧场景并显示新场景
    if(UserDefault::getInstance()->getIntegerForKey("backeffect",1) == 1){
		SimpleAudioEngine::getInstance()->playEffect("sound/GUITransitionClose.wav");
	}
    _inScene->setVisible(true);
	_outScene->setVisible(false);//父类的成员变量
}