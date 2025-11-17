//
// Created by 20619 on 2025/11/7.
//

#ifndef KINGDOMRUSH_STU_SIMPLEARTILLERYTOWERLVL3_H
#define KINGDOMRUSH_STU_SIMPLEARTILLERYTOWERLVL3_H

#include "cocos2d.h"
#include "BaseArtilleryTower.h"
USING_NS_CC;
class SimpleArtilleryTowerlvl3: public BaseArtilleryTower{
public:
    bool init() override;
    CREATE_FUNC(SimpleArtilleryTowerlvl3);
    void showUpdateMenu() override;
    void update1() override;
    void update2() override;
};


#endif //KINGDOMRUSH_STU_SIMPLEARTILLERYTOWERLVL3_H