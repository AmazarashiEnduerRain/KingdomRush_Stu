//
// Created by 20619 on 2025/11/7.
//

#ifndef KINGDOMRUSH_STU_SIMPLEARTILLERYTOWERLVL2_H
#define KINGDOMRUSH_STU_SIMPLEARTILLERYTOWERLVL2_H

#include "cocos2d.h"
#include "BaseArtilleryTower.h"

USING_NS_CC;

class SimpleArtilleryTowerlvl2: public BaseArtilleryTower{
public:
    bool init() override;
    CREATE_FUNC(SimpleArtilleryTowerlvl2);
    void updateTower() override;
    void showUpdateMenu() override;
};


#endif //KINGDOMRUSH_STU_SIMPLEARTILLERYTOWERLVL2_H