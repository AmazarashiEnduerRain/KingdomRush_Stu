//
// Created by 20619 on 2025/11/20.
// 该类进行数据存储以及缩略图显示

#ifndef KINGDOMRUSH_STU_TOWERDESC_H
#define KINGDOMRUSH_STU_TOWERDESC_H

#include "cocos2d.h"
#include <string>

USING_NS_CC;

class TowerDesc : public Sprite {
public:
    virtual bool myinit(std::string name);
    static TowerDesc *createTowerDesc(std::string name);
    CREATE_FUNC(TowerDesc);

    Sprite *towerDescPic;//缩略图精灵

    std::string towerThumbFileName;//缩略图文件名
    std::string towerDescFileName;//右侧显示的大图文件名

    int id;//索引
    std::string towerName;//塔名称
    std::string attackSpeed;//攻速
    std::string attackValue;//攻击力
    std::string attackRange;//射程
    std::string note;//描述

    void setData(
        Sprite *towerDescPic,
        const std::string& towerThumbFileName,
        const std::string& towerDescFileName,
        int id,
        std::string towerName,
        std::string attackSpeed,
        std::string attackValue,
        std::string attackRange,
        std::string note
    );
};
#endif //KINGDOMRUSH_STU_TOWERDESC_H
