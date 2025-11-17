//
// Created by 20619 on 2025/10/23.
//

#include "BaseArrowTower.h"
#include "Data/GameManager.h"

void BaseArrowTower::initTower(int level){
    //根据等级加载不同的塔的图片
    towerBase = Sprite::createWithSpriteFrameName(__String::createWithFormat("archer_tower_000%d.png",level)->getCString());

    //根据等级加载不同的射手图片
    shooter_1 = Sprite::createWithSpriteFrameName(__String::createWithFormat("tower_archer_lvl%d_shooter_0001.png",level)->getCString());
    shooter_2 = Sprite::createWithSpriteFrameName(__String::createWithFormat("tower_archer_lvl%d_shooter_0001.png",level)->getCString());

    //设置射手在塔上的位置
    shooter_1->setPosition(Point(towerBase->getContentSize().width/2-10,towerBase->getContentSize().height/2+18));
    shooter_2->setPosition(Point(towerBase->getContentSize().width/2+10,towerBase->getContentSize().height/2+18));

    towerBase->addChild(shooter_1);
    towerBase->addChild(shooter_2);

    addChild(towerBase);

    //初始化射击标记，让右边的先射击
    shootTag = RIGHT_ARCHER_SHOT;
}

void BaseArrowTower::addTerrain(){
    terrain = Sprite::createWithSpriteFrameName("terrain_archer_0004.png");
    terrain->setAnchorPoint(Point(0.5,1));
    addChild(terrain,-1);//添加至最底层（z=-1）
}

Bullet* BaseArrowTower::ArrowTowerBullet(){
    return nullptr;//虚函数基类实现
}

void BaseArrowTower::shoot(float dt){
    auto instance = GameManager::getInstance();
    //auto bulletVector = instance->bulletVector;
	checkNearestMonster(); //计算最近的怪物

	char temp1[20];
	sprintf(temp1, "level%d_shoot_down", level);
	char temp2[20];
	sprintf(temp2, "level%d_shoot_top", level);

	if(nearestMonster!=NULL && nearestMonster->getCurrHp() > 0 ){
		auto currBullet = ArrowTowerBullet();
		//instance->bulletVector.pushBack(currBullet);

		//计算塔到怪物的位置向量
		Point shootVector = nearestMonster->baseSprite->getPosition() - this->getParent()->getPosition();

		float startAngle = currBullet->getRotation();//获取箭矢精灵自身的初始旋转角度
		float endAngle = 0;

		auto pVectr = currBullet->getPosition()-shootVector;
        float angleRadians=atan(pVectr.y/pVectr.x);
        float angleDegrees = CC_RADIANS_TO_DEGREES(angleRadians);

		if(shootVector.x - currBullet->getPosition().x<=0)//向左攻击
		{
			startAngle = startAngle + abs(angleDegrees);//初始弓箭角度
			endAngle = -90;//结束角度
			if(shootTag == LEFT_ARCHER_SHOT)//轮到1号弓箭手
			{
				currBullet->setPosition(Point(0,30));//子弹设置在弓箭手所在位置
				shooter_1->setFlippedX(true);
				if(shootVector.y - currBullet->getPosition().y<=0)
					shooter_1->runAction(Animate::create(AnimationCache::getInstance()->getAnimation(temp1)));
				else
					shooter_1->runAction(Animate::create(AnimationCache::getInstance()->getAnimation(temp2)));//攻击动画
				shootTag = RIGHT_ARCHER_SHOT;
			}
			else//轮到2号弓箭手
			{
				currBullet->setPosition(Point(10,30));
				shooter_2->setFlippedX(true);
				if(shootVector.y - currBullet->getPosition().y<=0)
					shooter_2->runAction(Animate::create(AnimationCache::getInstance()->getAnimation(temp1)));
				else
					shooter_2->runAction(Animate::create(AnimationCache::getInstance()->getAnimation(temp2)));
				shootTag = LEFT_ARCHER_SHOT;
			}
		}else{
			startAngle = startAngle - abs(angleDegrees);
			endAngle = 270;
			if(shootTag == LEFT_ARCHER_SHOT){
				currBullet->setPosition(Point(0,30));
				shooter_1->setFlippedX(false);
				if(shootVector.y - currBullet->getPosition().y<=0)
					shooter_1->runAction(Animate::create(AnimationCache::getInstance()->getAnimation(temp1)));
				else
					shooter_1->runAction(Animate::create(AnimationCache::getInstance()->getAnimation(temp2)));
				shootTag = RIGHT_ARCHER_SHOT;
			}
			else{
				currBullet->setPosition(Point(10,30));
				shooter_2->setFlippedX(false);
				if(shootVector.y - currBullet->getPosition().y<=0)
					shooter_2->runAction(Animate::create(AnimationCache::getInstance()->getAnimation(temp1)));
				else
					shooter_2->runAction(Animate::create(AnimationCache::getInstance()->getAnimation(temp2)));
				shootTag = LEFT_ARCHER_SHOT;
			}
		}
		//弧线
		ccBezierConfig bezier;
		if(shootTag == LEFT_ARCHER_SHOT) SoundManager::playArrowShoot2();
		else  SoundManager::playArrowShoot1();
		//两个控制点
		bezier.controlPoint_1 = Point(currBullet->getPosition().x,currBullet->getPosition().y + 200);
		bezier.controlPoint_2 = Point(shootVector.x,shootVector.y + 200);;
		bezier.endPosition = shootVector;

		auto action = Spawn::create(BezierTo::create(0.5f, bezier),RotateTo::create(0.5f,endAngle),NULL);//组合动作，飞行，同时旋转
		//攻击属性给弓箭
		currBullet->setBulletAction(action);
		currBullet->shoot();
		currBullet = NULL;
	}
}