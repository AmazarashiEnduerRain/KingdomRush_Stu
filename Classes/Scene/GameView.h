//
// Created by 20619 on 2025/11/19.
// 选关大地图界面。包含UI层(GameViewMenu)，地图拖拽，关卡旗帜，道路，解锁动画

#ifndef KINGDOMRUSH_STU_GAMEVIEW_H
#define KINGDOMRUSH_STU_GAMEVIEW_H

#include "cocos2d.h"
#include "Road/Road.h"
#include "Sprite/MapFlag.h"
#include "Data/GameManager.h"
USING_NS_CC;
class GameView : public Layer{
public:
    static Scene* createScene();
    bool init() override;
    CREATE_FUNC(GameView);

    void onTouchesBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event *event) override;
    void onTouchesMoved(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event *event) override;
    void onKeyReleased(EventKeyboard::KeyCode keycode, Event* event) override;//安卓适配

    void onEnterTransitionDidFinish() override;//处理解锁动画
private:
    GameManager *instance;

    Sprite* bgSprite;//地图大背景
    Size winSize;
    Road* road;//道路层
    Vector<MapFlag*> mapFlagVector;//存储所有关卡旗帜
    std::vector<Point> mapFlagPointVector;//存储所有关卡旗帜位置

    void addMapFlag();//添加所有已解锁旗帜
    void addRoad();//道路层添加
    void addNewMapFlag(int num);//添加新解锁旗帜
};
#endif //KINGDOMRUSH_STU_GAMEVIEW_H