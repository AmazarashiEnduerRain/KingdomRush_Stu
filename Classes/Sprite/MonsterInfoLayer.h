//
// Created by 20619 on 2025/11/13.
// 在界面底部显示玩家当前点击的怪物的详细信息

#ifndef KINGDOMRUSH_STU_MONSTERINFOLAYER_H
#define KINGDOMRUSH_STU_MONSTERINFOLAYER_H

#include "cocos2d.h"
#include "Monster/BaseMonster.h"
USING_NS_CC;

class MonsterInfoLayer : public Sprite{
public:
    static MonsterInfoLayer* createMonsterInfoLayer(BaseMonster* monster);
    bool init(BaseMonster* monster);

    void setMonsterInfo();//填充UI元素
    BaseMonster* mBaseMonster;
    Sprite* info_bg;//信息面板的背景精灵
    int maxHp;
    void updateMonsterHp(float dt);//每帧更新生命值文本
    Label* hpLabel;
};


#endif //KINGDOMRUSH_STU_MONSTERINFOLAYER_H