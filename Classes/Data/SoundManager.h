//
// Created by 20619 on 2025/11/1.
//

#ifndef KINGDOMRUSH_STU_SOUNDMANAGER_H
#define KINGDOMRUSH_STU_SOUNDMANAGER_H

class SoundManager{
public:
	static void playClickEffect();//点击音效
	static void playIncomingWave();//敌人来袭音效
	static void playNextWaveReady();//下一波已准备好的音效

	static void playTowerMenu();//打开建造/升级菜单
	static void playShipOpen();//船门打开
	static void playWinStars();//星星计数

	//防御塔（建造、升级、出售）
	static void playTowerBuilding();
	static void playTowerUpdate();
	static void playTowerSell();

	//野人塔
	static void playTotemReady();
	static void playTotemShot();
	static void playTotemSpirits();
	static void playTotemWeakness();

	//箭塔
	static void playArrowShoot1();
	static void playArrowShoot2();
	static void playArrowRelease();
	static void playArcherReady();
	static void playArcher2Ready();
	static void playArcher3Ready();

	//弩塔
	static void playCrossbowReady();
	static void playCrossbowMultishot();
	static void playCrossbowEagle();

	//地震塔
	static void playEarthquakeReady();
	static void playEarthquakeHit();
	static void playEarthquakeDrillin();
	static void playEarthquakeDrillOut();
	static void playEarthquakeLava();

	//机器人
	static void playMechReady();
	static void playMechWalk();
	static void playMechShit();
	static void playMechLoading();

	//炮塔
	static void playArtilleryReady();
	static void playArtillery2Ready();
	static void playArtillery3Ready();
	static void playBomb();

	//兵营塔
	static void playRallyPointPlaced();
	static void playBarrackReady();
	static void playBarrack2Ready();
	static void playBarrack3Ready();
	static void playBarrackOpendoor();
	static void playBarrackMove();
	static void playAssassinMove();

	//龙卷风塔
	static void playArchmageReady();
	static void playArchmageShot();
	static void playArchmageTwister();
	static void playArchmagePrecharge();

	//基础魔法塔
	static void playMageTowerReady();
	static void playMageTower2Ready();
	static void playMageTower3Ready();
	static void playMageTowerShot();

	//NEC
	static void playNecTowerReady();
	static void playDKReady();
	static void playNecShot();
	static void playDKTaunt();

	//陨石
	static void playFireballHit();
	static void playFireballUnleash();

	//关卡结束
	static void playQuestCompleted();
	static void playQuestFailed();

	//技能
	static void playReinforcement();
	static void playCash();
	static void playFreeze();
	static void playHearts();

	//猩猩BOSS
	static void playChestdrum();
	static void playChimps_1();
	static void playChimps_2();
	static void playChimps_3();
	static void playMonoDeath();

	static void playWelcomeBackMusic();//主菜单音乐
	static void playJungleBattle();//丛林战斗音乐
	static void playDesertBattle();//荒野战斗音乐
	static void playGameTheme1();//游戏地图音乐

	//Boss 100的音效
	static void playEfreetiLaugh();
	static void playEfreetiClap();
	static void playEfreetiDeath();
private:
	static bool cheakEffectState();//检查音效设置（根据玩家选择判断是否播放音效）
};


#endif //KINGDOMRUSH_STU_SOUNDMANAGER_H