//
// Created by 20619 on 2025/11/14.
//

#ifndef KINGDOMRUSH_STU_TOWERINFOLAYER_H
#define KINGDOMRUSH_STU_TOWERINFOLAYER_H

#include "cocos2d.h"
#include "Tower/BaseTower.h"
USING_NS_CC;

class TowerInfoLayer : public Sprite{
public:
    static TowerInfoLayer* createTowerInfoLayer(TowerType towerType);
    virtual bool init(TowerType towerType);
    void setTowerInfo(TowerType towerType);
    Sprite* info_bg;
};
#endif //KINGDOMRUSH_STU_TOWERINFOLAYER_H