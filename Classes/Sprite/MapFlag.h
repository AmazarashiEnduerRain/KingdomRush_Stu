//
// Created by 20619 on 2025/11/14.
// 在关卡选择界面所看见的代表关卡的旗帜

#ifndef KINGDOMRUSH_STU_MAPFLAG_H
#define KINGDOMRUSH_STU_MAPFLAG_H

#include "cocos2d.h"
#include "Data/GameManager.h"
USING_NS_CC;

class MapFlag : public Sprite{
public:
    MapFlag();
    ~MapFlag();
    virtual bool initWithLevel(int Level);
    CREATE_FUNC(MapFlag);
    static MapFlag* createWithLevel(int Level);
    void changeType(int type);//辅助函数，用于改变旗帜外观（在关卡完成时调用）
private:
    Sprite* wings;//完美通关时的“翅膀”装饰
    CC_SYNTHESIZE(int, type, Type);
    CC_SYNTHESIZE(int, level, Level);
    Sprite* flag;//旗帜主要部分的视觉精灵
    Sprite* star_0;
    Sprite* star_1;
    Sprite* star_2;//指向旗帜上方三颗星星

    void initStar();
    void addStar();
    void startSuccessAnimation();//通关后动画
    void startDropdownAnimation();//新关卡解锁动画

    bool onTouchBegan(Touch* touch, Event* event);
    void onTouchEnded(Touch* touch, Event* event);
    void starAnimation();
    void setStarShine(int num);
    Vector<Sprite*> starVector;
    GameManager *instance;//缓存GameManager单例，避免重复调用getInstance
    void setStarClose();//将所有星星设置为未点亮状态
};


#endif //KINGDOMRUSH_STU_MAPFLAG_H