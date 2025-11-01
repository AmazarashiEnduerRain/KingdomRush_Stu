//
// Created by 20619 on 2025/11/1.
//

#ifndef KINGDOMRUSH_STU_MYANIMATION_H
#define KINGDOMRUSH_STU_MYANIMATION_H

#include "cocos2d.h"
USING_NS_CC;

class MyAnimation{
public:
    static MyAnimation* getInstance();

    void init();//主初始化函数，调用下方其他的初始化函数
    void init_desert();
    void init_jungle();
    void init_ArcherTower();
    void init_ArtilleryTower();
    void init_Executioner();

    void init_Wasp_Queen();
    void init_Wasp_Hornet();
    void init_Scorpion();
    void init_Munra();
    void init_Thug();
    void init_Raider();
    void init_Gorilla();
    void init_Priest();
    void init_Shaman();
    void init_Hunter();
    void init_Canibal();

    void init_Shield();
    void init_WingRider();
    void init_Wolf();
    void init_reinforce();
    void init_Immortal();
    void init_Tremor();
    void init_Fallen();

    void init_blazefang();
    void init_broodguard();
    void init_elite();
    void init_myrmidon();
    void init_nightscale();
    void init_Quetza();
    void init_underground();

    void init_earthquakeTower();
    void init_ArchMageTower();
    void init_mechsTower();
    void init_NecromancerTower();
    void init_BarracksTower();
    void init_MageTower();
    void init_CossbowHunterTower();
    void init_TotemTower();
    void init_monster_blood();

    void init_BossCanibal();
    void release_BossEfreeti();
    void init_BossEfreeti();
    void release_BossCanibal();//release函数进行动画缓存释放

    //根据帧名前缀，开始/结束编号、延迟来创建动画
    Animation* createAnimation(const char* prefixName, int start,int end, float delay);
    //创建反向播放的动画
    Animation* createAnimationR(const char* prefixName, int start,int end, float delay);
    //创建一个最后额外附加一帧的动画
    Animation* createAnimation(const char* prefixName, int start,int end, float delay,std::string lastFrame);
    void init_others();
private:
    static MyAnimation * instance;
};

#endif //KINGDOMRUSH_STU_MYANIMATION_H