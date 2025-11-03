//
// Created by 20619 on 2025/11/3.
// 轻量级数据容器，用于在关卡开始时从.plist配置文件中读取并临时存储一只怪物的生成信息

#ifndef KINGDOMRUSH_STU_GROUPMONSTER_H
#define KINGDOMRUSH_STU_GROUPMONSTER_H

#include "cocos2d.h"

USING_NS_CC;

class GroupMonster: public Node{
public:
    static GroupMonster* initGroupEnemy(int type, int road, int path);//静态方法，创建GroupMonster的唯一入口
    CREATE_FUNC(GroupMonster);
    //保存怪物类型
    CC_SYNTHESIZE(int, type, Type);
    //不同出口（主路线）
    CC_SYNTHESIZE(int, road, Road);
    //不同路线（子路径）
    CC_SYNTHESIZE(int, path, Path);
};

#endif //KINGDOMRUSH_STU_GROUPMONSTER_H