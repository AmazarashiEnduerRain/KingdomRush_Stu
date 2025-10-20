//
// Created by 20619 on 2025/10/14.
//

#ifndef KINGDOMRUSH_STU_BASEMAP_H
#define KINGDOMRUSH_STU_BASEMAP_H

#include "cocos2d.h"
#include "Layer/TouchLayer.h"
#include "Layer/PlayerStateMenu.h"
#include "Sprite/WaveFlag.h"
#include "Monster/GroupMonster.h"
USING_NS_CC;

class BaseMap : public Layer{
public:
    CREATE_FUNC(BaseMap);//cocos2d-x的宏，用于生成静态create()方法

    //当前关卡。level变量用于存储当前是第几关
    CC_SYNTHESIZE(int, level, Level);
    //玩家状态栏，指向PlayerStateMenu对象的指针，更新UI
    PlayerStateMenu* playerState;
    //将外部创建的PlayerStateMenu与当前地图绑定
    void bindPlayerStateMenu(PlayerStateMenu* playerState);
    //地图精灵。指向背景地图图片
    Sprite* mapSprite;
    //处理触摸事件的透明层（将游戏触摸与UI触摸分离）
    TouchLayer* mTouchLayer;
protected:
    void initTouchLayer();

    //本关难度
    int difficulty;
    int wave;
    int maxWave;
    int gold;
    int life;
    int startGold;
    int maxLife;
    unsigned int time;

    //wave怪物容器容器。第一层索引代表波数，第二层索引代表出怪的时间点，第三层存储需要创建的所有怪物的信息
    std::vector<std::vector<Vector<GroupMonster*>>> waveVector;
    //加载路径和关卡数据，从.plist配置文件中进行读取
    void loadPathFromPlist();
    void loadAndSetLevelData();
    //存储路径的容器 从内到外为点，线路，路线
    std::vector<std::vector<std::vector<Point>>> path;
    //屏幕尺寸
    Size winSize;

    //下一波提示精灵 0为路线1,1为路线2。玩家可以点击waveFlag以提前出怪
    Vector<WaveFlag*> waveFlags;
    void addWaveProgressBars(std::vector<Point> waveFlagLocations);
    void showWaveProgressBars(float dt);

    void onEnterTransitionDidFinish() override;

    //不同关卡不同的事件处理。允许子类为特定波数定义特殊事件（如Boss出场前的动画）
    virtual void waveEvent();
    //设置初始地图位置
    void setMapPosition();
    //更新金钱和生命
    void updateGoldAndLife();
    void update(float dt) override;

    //胜利函数
    void victory();
    //结束标记
    bool isEnd;
    //开始标记
    bool isStart;
    //开始新的一波敌人
    virtual void addWaves(float dt);
    //添加怪物
    virtual void addMonsters(float dt);
    //初始化地图
    void initMap();
    //添加不同地图装饰物
    virtual void addOrnament(){};
    //添加建塔点
    virtual void addTerrains(){};
    //退出
    void onExitTransitionDidStart() override;
    void onExit() override {};
};


#endif //KINGDOMRUSH_STU_BASEMAP_H