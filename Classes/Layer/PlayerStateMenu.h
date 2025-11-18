//
// Created by 20619 on 2025/11/18.
//

#ifndef KINGDOMRUSH_STU_PLAYERSTATEMENU_H
#define KINGDOMRUSH_STU_PLAYERSTATEMENU_H

#include "cocos2d.h"
#include "TouchLayer.h"
#include "Data/GameManager.h"
#include "Tower/BaseTower.h"
#include "Monster/BaseMonster.h"
#include "GameOption.h"
USING_NS_CC;

//管理信息弹窗的TAG
#define TOWER_INFO 1001
#define MONSTER_INFO 1002

class PlayerStateMenu : public Layer{
public:
    static Scene* createScene();
    bool init() override;
    CREATE_FUNC(PlayerStateMenu);

    void onEnterTransitionDidFinish() override;//入场动画
    void startProgressTimers();//开启技能冷却倒计时

    Sprite* stateSprite;//顶部状态栏背景
    Sprite* pause;//暂停按钮
    Label* lifeLabel;//生命值
    Label* goldLabel;//金钱
    Label* waveLabel;//波次

    Sprite* thunderStoneSprite;//火雨图标
    Sprite* paratrooperSprite;//援兵图标
    Sprite* packSprite;//背包按钮

    Sprite* backPackSprite;//背包展开背景
    Sprite* backPack_icons_Sprite[6];//背包道具图标
    std::string stringForSkillFileName;//辅助字符串

    void updateStoneProgress(float Dt);//火雨冷却回调
    void updateParatrooperProgress(float Dt);//援兵冷却回调
    bool completeThunder;//火雨就绪
    bool completeParatrooper;//援兵就绪
    ProgressTimer* paratrooperTimer;////援兵冷却遮罩
    ProgressTimer* stoneTimer;//火雨冷却遮罩

    GameManager* instance;
    TouchLayer* mTouchLayer;//用于切换触摸模式

    //数据管理方法
    void setLife(int life);
    void setGold(int gold);
    void setWave(int thisWave,int totalWave);

    //控制技能冷却开始
    void startParatrooper();
    void startStone();

    //信息面板控制
    void showTowerInfo(TowerType towerType);
    void removeTowerInfo();
    void showMonsterInfo(BaseMonster* monster);
    void removeMonsterInfo();

    //暂停菜单控制
    void removeGameOption();
private:
    //关卡信息，用于重玩时传参
    CC_SYNTHESIZE(int, level, Level);
    CC_SYNTHESIZE(int, difficult, Difficult);

    void shopSkill(int type);//商店道具的实现逻辑

    void frozenMonsters();
    void reFrozenMonsters(float dt);
    void clearMonsters();//核弹逻辑，进行清屏
    bool isFrozen;//标记当前是否处于冰冻状态

    GameOption *gameOption;//暂停菜单
    void addGameOption();
    void pauseGame();
    void initGameOption();
};

#endif //KINGDOMRUSH_STU_PLAYERSTATEMENU_H