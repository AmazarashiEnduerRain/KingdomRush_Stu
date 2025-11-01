//
// Created by 20619 on 2025/11/1.
//

#ifndef KINGDOMRUSH_STU_GAMEMANAGER_H
#define KINGDOMRUSH_STU_GAMEMANAGER_H

#include "Bullet/Bullet.h"
#include "cocos2d.h"
#include "Monster/BaseMonster.h"
#include "Tower/BaseTower.h"
#include "Layer/TouchLayer.h"

USING_NS_CC;

class GameManager{
public:
    void CreateGameManager(int slot);

    Vector<BaseMonster*> monsterVector;

    static GameManager* getInstance();

    //以下为键模板。其并不存储数据，而是作为格式化字符串模板，以用于访问UserDefault

    //某存档是否已经新建，true表示新建，false表示未新建
    char SLOTX_ISEXIT[20];
    //某关卡是否完成,0表示未完成，1表示完成
    char LEVELX_ISDOWN[20];
    //某关卡得到的星星数目
    char LEVELX_STARNUM[20];
    //剩余星星数目
    char SLOTX_STARLEFT[20];
    //某存档通关数
    char SLOTX_DOWNCOUNT[20];
    //某存档最新开启的
    char LEVELX_NEWDOWN[20];
    //总星星数
    char SLOTX_STAR[20];
    //商店
    char SLOTX_SHOP[20];
    //宝石
    char SLOTX_GEM[20];
    //当前激活的存档槽位编号
    int SLOTNUM;
    //实时金钱
    int MONEY;
    //实时生命
    int LIFE;
    // 关卡编号
    int LEVEL;

    void setInstance(int tag);// 在游戏开始时调用，接收槽位编号以初始化所有键名
    static void eraseAll(); //在关卡退出时清空monsterVector，防止数据污染
private:
    static GameManager * instance;
};

#endif //KINGDOMRUSH_STU_GAMEMANAGER_H