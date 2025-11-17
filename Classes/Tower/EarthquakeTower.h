//
// Created by 20619 on 2025/11/8.
//

#ifndef KINGDOMRUSH_STU_EARTHQUAKETOWER_H
#define KINGDOMRUSH_STU_EARTHQUAKETOWER_H

#include "cocos2d.h"
#include "Tower/BaseTower.h"
#include "Bullet/EarthquakeSmoke.h"
#include "Bullet/Lava.h"
USING_NS_CC;
class EarthquakeTower: public BaseTower{
public:
    bool init() override;
    CREATE_FUNC(EarthquakeTower);
private:
    void showUpdateMenu() override;

    //塔的视觉组件
    Sprite* towerBase;
    Sprite* operation;//塔身动画
    Sprite* glow;//发光特效
    Sprite* HitDecal;//地面裂痕动画
    Sprite* light;//钻探技能灯光

    //特效对象
    Lava* lava;//熔岩
    EarthquakeSmoke* hitSmoke;//震击烟雾

    void shoot(float dt);
    void attackMonsters(int force);//范围伤害和减速
    int attackCount;
    Point drill();
    void addTerrain();
    void checkNearestMonster() override;//仅攻击地面单位
};



#endif //KINGDOMRUSH_STU_EARTHQUAKETOWER_H