//
// Created by 20619 on 2025/11/8.
//

#ifndef KINGDOMRUSH_STU_MECHSTOWER_H
#define KINGDOMRUSH_STU_MECHSTOWER_H

#include "cocos2d.h"
#include "BaseBarracksTower.h"
#include "Soldier/Mecha.h"
USING_NS_CC;

class MechsTower: public BaseBarracksTower{
public:

    bool init() override;
    CREATE_FUNC(MechsTower);
    void setRallyPoint(Point location) override;//设置机甲位置
private:
    void initMech();//生成机甲的初始化函数
    Mecha* mecha;
    void showUpdateMenu() override;
    void playReadySound();
    void sellTower() override;//售卖塔时手动移除机甲
};


#endif //KINGDOMRUSH_STU_MECHSTOWER_H