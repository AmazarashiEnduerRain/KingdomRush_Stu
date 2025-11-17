//
// Created by 20619 on 2025/11/11.
// Road类本身在场景中即为一个节点，可以移动、添加和显示
// 这是游戏选择关卡界面的动画以及界面

#ifndef KINGDOMRUSH_STU_ROAD_H
#define KINGDOMRUSH_STU_ROAD_H

#include "cocos2d.h"
USING_NS_CC;
class Road : public Sprite{
public:
    Road();
    ~Road();
    bool init() override;
    CREATE_FUNC(Road);

    virtual void buildRoadAnimation(int num);//播放指定的路的修建动画
    virtual void setRoadReady();//确定哪些路应当显示

    Vector<Sprite*> roadVector;//存储所有路段对象
    Vector<Animation*> roadAnimaitonVector;//存储路的修建动画
    void initRoadAnimation();//初始化路的动画资源
};


#endif //KINGDOMRUSH_STU_ROAD_H