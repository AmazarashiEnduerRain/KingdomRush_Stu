//
// Created by 20619 on 2025/11/20.
//

#ifndef KINGDOMRUSH_STU_ENEMYSCENE_H
#define KINGDOMRUSH_STU_ENEMYSCENE_H

#include "cocos2d.h"
#include "EnemyDesc.h"
USING_NS_CC;

class EnemyScene : public cocos2d::Layer{
public:
    static cocos2d::Scene* createScene();
    bool init() override;
    CREATE_FUNC(EnemyScene);

    //怪物百科不止一页。故要有翻页回调
    void lastPage(Ref* pSender);
    void nextPage(Ref* pSender);

    bool onTouchBegan(Touch* touch, Event* event) override;
    void onTouchEnded(Touch* touch, Event* event) override;
private:
    int pageNum;//索引

    Sprite* bigSprite;
    Size visibleSize;

    MenuItemSprite* spriteLeftButton;
    MenuItemSprite* spriteRightButton;
    Layer* ccmenuCreep[3];//三个页容器

    Label* labelPage;
    Label* labelName;

    //六个属性标签
    Label* labelBloodValue;
    Label* labelAttackValue;
    Label* labelDefenseValue;
    Label* labelMagicDefenseValue;
    Label* labelMovementSpeed;
    Label* labelLifeNumber;
    //六个值
    Label* labelBloodValue1;
    Label* labelAttackValue1;
    Label* labelDefenseValue1;
    Label* labelMagicDefenseValue1;
    Label* labelMovementSpeed1;
    Label* labelLifeNumber1;

    Label* labelNotice;
    Label* labelNotice1;

    Sprite* selectionFrame;
    MoveTo *moveFrame;

    char enemyIdString[8];
    EnemyDesc* enemyDesc[50];//存储所有怪物图鉴
};


#endif //KINGDOMRUSH_STU_ENEMYSCENE_H