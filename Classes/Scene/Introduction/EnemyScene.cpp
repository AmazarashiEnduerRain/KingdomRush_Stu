//
// Created by 20619 on 2025/11/20.
//

#include "EnemyScene.h"
#include "Data/SoundManager.h"

USING_NS_CC;

Scene* EnemyScene::createScene(){
    auto scene = Scene::create();
    auto enemyInfLayer = EnemyScene::create();
    scene->addChild(enemyInfLayer);
    return scene;
}

bool EnemyScene::init(){
    if ( !Layer::init() ) return false;

	visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(EnemyScene::onTouchBegan, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(EnemyScene::onTouchEnded, this);

	//背景循环铺设
	for(int i = 0;i < 4;i++){
		for(int j = 0;j < 5;j++){
			auto sprite = Sprite::createWithSpriteFrameName("encyclopedia_bgTile.png");
			sprite->setPosition(Point(i * 310,j * 150));
			sprite->setAnchorPoint(Point(0,0));
			addChild(sprite);
		}
	}

	//书页背景
    auto bookRight = Sprite::createWithSpriteFrameName("encyclopedia_book_pg.png");
    bookRight->setPosition(Vec2(visibleSize.width * 3 / 4 + origin.x, visibleSize.height / 2 + origin.y));
    auto bookLeft = Sprite::createWithSpriteFrameName("encyclopedia_book_pg.png");
    bookLeft->setPosition(Vec2(visibleSize.width / 4 + origin.x, visibleSize.height / 2 + origin.y));
	bookLeft->setFlippedX(true);
    this->addChild(bookRight, 1);
	this->addChild(bookLeft, 1);

	//关闭按钮
	auto closeBtn = MenuItemSprite::create(
			Sprite::createWithSpriteFrameName("encyclopedia_tow_creep_close_0001.png"),
			Sprite::createWithSpriteFrameName("encyclopedia_tow_creep_close_0001.png"));
	closeBtn->setPosition(Vec2(visibleSize.width - closeBtn->getContentSize().width * 3 / 2  + origin.x,
								visibleSize.height + origin.y - closeBtn->getContentSize().height / 2));
	closeBtn->setCallback([&](Ref *pSender){
		SoundManager::playClickEffect();
		Director::getInstance()->popScene();
	});
	auto menuclose = Menu::create(closeBtn,NULL);
	menuclose->setPosition(Vec2::ZERO);
	this->addChild(menuclose,2);

	//选中框
	selectionFrame = Sprite::createWithSpriteFrameName("encyclopedia_creep_thumbs_frame_0002.png");
    selectionFrame->setPosition(Point(visibleSize.width * 0.17, visibleSize.height * 0.75));
	this->addChild(selectionFrame,3);

	//创建左右翻页精灵
	auto spriteRight = Sprite::createWithSpriteFrameName("encyclopedia_tow_creep_arrow_0003.png");
	auto spriteLeft = Sprite::createWithSpriteFrameName("encyclopedia_tow_creep_arrow_0003.png");
	//无效图标(不可点击时的显示)
	auto spriteRightNull = Sprite::createWithSpriteFrameName("encyclopedia_tow_creep_arrow_0001.png");
	auto spriteLeftNull = Sprite::createWithSpriteFrameName("encyclopedia_tow_creep_arrow_0001.png");
	//两个小翻页
	auto spriteRightLittle = Sprite::createWithSpriteFrameName("encyclopedia_tow_creep_arrow_0003.png");
	spriteRightLittle->setScale(0.9);
	auto spriteLeftLittle = Sprite::createWithSpriteFrameName("encyclopedia_tow_creep_arrow_0003.png");
	spriteLeftLittle->setScale(0.9);
	spriteLeft->setFlippedX(true);
	spriteLeftNull->setFlippedX(true);
	spriteLeftLittle->setFlippedX(true);

	//无效的拇指图标
	auto spriteCreepThumbNull = Sprite::createWithSpriteFrameName("encyclopedia_tower_thumbs_0121.png");
	//初始化拇指图标48个
	for(int i = 0; i < 48; i ++){
		std::string temp1 = "encyclopedia_creep_thumbs_02";
		std::string temp2 = "encyclopedia_creep_02";
		if(i < 9){
			temp1 = temp1 + '0';
			temp2 = temp2 + '0';
		}
		temp1 = temp1 + __String::createWithFormat("%d",i + 1)->getCString();
		temp2 = temp2 + __String::createWithFormat("%d",i + 1)->getCString();
		temp1 = temp1 + ".png";
		temp2 = temp2 + ".png";

		//图鉴呈现4 * 4网格状
		enemyDesc[i] = EnemyDesc::createEnemyDesc(temp1);
		enemyDesc[i]->setPosition(Point(visibleSize.width * (0.17 + (i % 4) * 0.085),
												visibleSize.height * (0.75 - ((i / 4) % 4) * 0.15)));
		_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener->clone(), enemyDesc[i]);
		enemyDesc[i]->enemyThumbFileName = temp1;
		enemyDesc[i]->enemyDescFileName = temp2;
		enemyDesc[i]->id = i;
	}

	//将图鉴分配至三页Layer中
	for(int i = 0 ; i < 3 ; i ++){
		ccmenuCreep[i] = Layer::create();
		ccmenuCreep[i]->setPosition(Vec2::ZERO);
		for(int j = 0 ; j < 16; j ++){
			ccmenuCreep[i]->addChild(enemyDesc[16 * i + j],2);//每页有16个图鉴
		}
		this->addChild(ccmenuCreep[i],2);
	}

	//初始化菜单可见性
	ccmenuCreep[0]->setVisible(true);
	ccmenuCreep[1]->setVisible(false);
	ccmenuCreep[2]->setVisible(false);

	//初始化说明大图
	bigSprite = Sprite::createWithSpriteFrameName(enemyDesc[0]->enemyDescFileName);
	bigSprite->setPosition(Vec2(visibleSize.width * 0.7,visibleSize.height * 0.75));
	this->addChild(bigSprite,2);

	//点击左翻页 & 动画
	spriteLeftButton = MenuItemSprite::create(
		spriteLeft,
		spriteLeftLittle,
		spriteLeftNull,
		CC_CALLBACK_1(EnemyScene::lastPage,this));
    auto ccmenuLeft = Menu::create(spriteLeftButton,NULL);
    spriteLeftButton->setPosition(Point(visibleSize.width * 0.2, visibleSize.height * 1 / 7));
	ccmenuLeft->setPosition(Vec2::ZERO);
    this->addChild(ccmenuLeft,2);
	spriteLeftButton->setEnabled(false);//初始时是第一页，不可左翻页

	//点击右翻页 & 动画
	spriteRightButton = MenuItemSprite::create(spriteRight,
		spriteRightLittle,
		spriteRightNull,
		CC_CALLBACK_1(EnemyScene::nextPage,this));
    auto ccmenuRight = Menu::create(spriteRightButton,NULL);
    spriteRightButton->setPosition(Point(visibleSize.width * 0.4,visibleSize.height * 1 / 7));
	ccmenuRight->setPosition(Vec2::ZERO);
    this->addChild(ccmenuRight,2);

	//字-敌人
    auto labelTitle = Label::createWithTTF("ENEMIES", "Marker Felt.ttf", 24);
    labelTitle->setPosition(Vec2(visibleSize.width * 0.3, visibleSize.height * 6 / 7));
	labelTitle->setColor(Color3B(0,0,0));
    this->addChild(labelTitle, 2);

	//字-页数
	pageNum = 0;
	labelPage = Label::createWithTTF(__String::createWithFormat("%d",pageNum + 1)->getCString(), "Marker Felt.ttf", 24);
    labelPage->setPosition(Vec2(visibleSize.width * 0.3, visibleSize.height * 1 / 7));
	labelPage->setColor(Color3B(0,0,0));
    this->addChild(labelPage, 2);

	//怪物名称
	labelName = Label::createWithTTF("", "Marker Felt.ttf", 24);
    labelName->setPosition(Vec2(visibleSize.width * 0.7, visibleSize.height * 0.60));
	labelName->setColor(Color3B(0,0,0));
    this->addChild(labelName, 2);

	//怪物血值
	labelBloodValue = Label::createWithTTF("", "Marker Felt.ttf", 16);
    labelBloodValue->setPosition(Vec2(visibleSize.width * 0.65, visibleSize.height * 0.50));
	labelBloodValue->setColor(Color3B(0,0,0));
    this->addChild(labelBloodValue, 2);

	//怪物攻击力
	labelAttackValue = Label::createWithTTF("", "Marker Felt.ttf", 16);
    labelAttackValue->setPosition(Vec2(visibleSize.width * 0.65, visibleSize.height * 0.45));
	labelAttackValue->setColor(Color3B(0,0,0));
    this->addChild(labelAttackValue, 2);

	//怪物物理防御力
	labelDefenseValue = Label::createWithTTF("", "Marker Felt.ttf", 16);
    labelDefenseValue->setPosition(Vec2(visibleSize.width * 0.65, visibleSize.height * 0.40));
	labelDefenseValue->setColor(Color3B(0,0,0));
    this->addChild(labelDefenseValue, 2);

	//怪物魔法防御力
	labelMagicDefenseValue = Label::createWithTTF("", "Marker Felt.ttf", 16);
    labelMagicDefenseValue->setPosition(Vec2(visibleSize.width * 0.65, visibleSize.height * 0.30));
	labelMagicDefenseValue->setColor(Color3B(0,0,0));
    this->addChild(labelMagicDefenseValue, 2);

	//怪物移动速度
	labelMovementSpeed = Label::createWithTTF("", "Marker Felt.ttf", 16);
    labelMovementSpeed->setPosition(Vec2(visibleSize.width * 0.65, visibleSize.height * 0.25));
	labelMovementSpeed->setColor(Color3B(0,0,0));
    this->addChild(labelMovementSpeed, 2);

	//怪物生命数量
	labelLifeNumber = Label::createWithTTF("", "Marker Felt.ttf", 16);
    labelLifeNumber->setPosition(Vec2(visibleSize.width * 0.65, visibleSize.height * 0.20));
	labelLifeNumber->setColor(Color3B(0,0,0));
    this->addChild(labelLifeNumber, 2);

	//怪物属性补充说明
    labelNotice = Label::createWithTTF("*", "Marker Felt.ttf", 16);
    labelNotice->setPosition(Vec2(visibleSize.width * 0.7, visibleSize.height * 0.15));
	labelNotice->setColor(Color3B(0,0,0));
    this->addChild(labelNotice, 2);

	//读取xml文档,放入ValueVector中
	ValueVector txt_vec = FileUtils::getInstance()->getValueVectorFromFile("creep.xml");
	int i = 0;
	for( auto& e : txt_vec){
		auto txt_map = txt_vec.at(i).asValueMap();
		int id_int = txt_map.at("id").asInt();
		if(id_int == i){
			enemyDesc[i]->enemyName = txt_map.at("EnemyName").asString();
			enemyDesc[i]->bloodValue = txt_map.at("BloodValue").asString();
			enemyDesc[i]->attackValue = txt_map.at("AttackValue").asString();
			enemyDesc[i]->defenseValue = txt_map.at("DefenseValue").asString();
			enemyDesc[i]->magicDefenseValue = txt_map.at("MagicDefenseValue").asString();
			enemyDesc[i]->movementSpeed = txt_map.at("MovementSpeed").asString();
			enemyDesc[i]->lifeNumber = txt_map.at("LifeNumber").asString();
			enemyDesc[i]->note = txt_map.at("Note").asString();
		}else if(id_int == 100){
			labelBloodValue->setString(txt_map.at("BloodValue").asString());
			labelAttackValue->setString(txt_map.at("AttackValue").asString());
			labelDefenseValue->setString(txt_map.at("DefenseValue").asString());
			labelMagicDefenseValue->setString(txt_map.at("MagicDefenseValue").asString());
			labelMovementSpeed->setString(txt_map.at("MovementSpeed").asString());
			labelLifeNumber->setString(txt_map.at("LifeNumber").asString());
		}
		i ++;
	}

	//怪物血值1
	labelBloodValue1 = Label::createWithTTF("", "Marker Felt.ttf", 16);
    labelBloodValue1->setPosition(Vec2(visibleSize.width * 0.75, visibleSize.height * 0.50));
	labelBloodValue1->setColor(Color3B(0,0,0));
    this->addChild(labelBloodValue1, 2);

	//怪物攻击力
	labelAttackValue1 = Label::createWithTTF("", "Marker Felt.ttf", 16);
    labelAttackValue1->setPosition(Vec2(visibleSize.width * 0.75, visibleSize.height * 0.45));
	labelAttackValue1->setColor(Color3B(0,0,0));
    this->addChild(labelAttackValue1, 2);

	//怪物物理防御力
	labelDefenseValue1 = Label::createWithTTF("", "Marker Felt.ttf", 16);
    labelDefenseValue1->setPosition(Vec2(visibleSize.width * 0.75, visibleSize.height * 0.40));
	labelDefenseValue1->setColor(Color3B(0,0,0));
    this->addChild(labelDefenseValue1, 2);

	//怪物魔法防御力
	labelMagicDefenseValue1 = Label::createWithTTF("", "Marker Felt.ttf", 16);
    labelMagicDefenseValue1->setPosition(Vec2(visibleSize.width * 0.75, visibleSize.height * 0.30));
	labelMagicDefenseValue1->setColor(Color3B(0,0,0));
    this->addChild(labelMagicDefenseValue1, 2);

	//怪物移动速度
	labelMovementSpeed1 = Label::createWithTTF("", "Marker Felt.ttf", 16);
    labelMovementSpeed1->setPosition(Vec2(visibleSize.width * 0.75, visibleSize.height * 0.25));
	labelMovementSpeed1->setColor(Color3B(0,0,0));
    this->addChild(labelMovementSpeed1, 2);

	//怪物生命数量
	labelLifeNumber1= Label::createWithTTF("", "Marker Felt.ttf", 16);
    labelLifeNumber1->setPosition(Vec2(visibleSize.width * 0.75, visibleSize.height * 0.20));
	labelLifeNumber1->setColor(Color3B(0,0,0));
    this->addChild(labelLifeNumber1, 2);

	//初始化显示第一个敌人的数据
	bigSprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(enemyDesc[0]->enemyDescFileName));
	labelName->setString(enemyDesc[0]->enemyName);
	labelBloodValue1->setString(enemyDesc[0]->bloodValue);
	labelAttackValue1->setString(enemyDesc[0]->attackValue);
	labelDefenseValue1->setString(enemyDesc[0]->defenseValue);
	labelMagicDefenseValue1->setString(enemyDesc[0]->magicDefenseValue);
	labelMovementSpeed1->setString(enemyDesc[0]->movementSpeed);
	labelLifeNumber1->setString(enemyDesc[0]->lifeNumber);
	labelNotice->setString(enemyDesc[0]->note);

	selectionFrame->setPosition(enemyDesc[0]->getPosition());
	selectionFrame->setVisible(true);
	return true;
}

//左翻页
void EnemyScene::lastPage(Ref* pSender){
	SoundManager::playClickEffect();
	pageNum --;
	if(pageNum == 0) spriteLeftButton->setEnabled(false);
	else {
		spriteLeftButton->setEnabled(true);
		spriteRightButton->setEnabled(true);
	}
	labelPage->setString(__String::createWithFormat("%d",pageNum + 1)->getCString());

	ccmenuCreep[pageNum]->setVisible(true);
	ccmenuCreep[pageNum + 1]->setVisible(false);
	selectionFrame->setVisible(false);//翻页后选中框隐藏
}

//右翻页
void EnemyScene::nextPage(Ref* pSender){
	SoundManager::playClickEffect();
	pageNum ++;
	if(pageNum == 2){
		spriteRightButton->setEnabled(false);
		spriteLeftButton->setEnabled(true);
	}else spriteLeftButton->setEnabled(true);

	labelPage->setString(__String::createWithFormat("%d",pageNum + 1)->getCString());

	ccmenuCreep[pageNum]->setVisible(true);
	ccmenuCreep[pageNum - 1]->setVisible(false);
	selectionFrame->setVisible(false);
}

//怪物描述
bool EnemyScene::onTouchBegan(Touch* touch, Event* event){
	auto target = static_cast<EnemyDesc*>(event->getCurrentTarget());
	Point locationInNode = target->convertTouchToNodeSpace(touch);
	Size size = target->enemyDescPic->getContentSize();
	Rect rect = Rect(-size.width / 2, -size.height / 2, size.width, size.height);
	if (rect.containsPoint(locationInNode) && target->getParent()->isVisible()){
		SoundManager::playClickEffect();

		bigSprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(target->enemyDescFileName));
		labelName->setString(target->enemyName);
		labelBloodValue1->setString(target->bloodValue);
		labelAttackValue1->setString(target->attackValue);
		labelDefenseValue1->setString(target->defenseValue);
		labelMagicDefenseValue1->setString(target->magicDefenseValue);
		labelMovementSpeed1->setString(target->movementSpeed);
		labelLifeNumber1->setString(target->lifeNumber);
		labelNotice->setString(target->note);

		moveFrame = MoveTo::create(0.1f,target->getPosition());//设置图标的位移时间，位移目标地址
		selectionFrame->runAction(moveFrame);
		selectionFrame->setVisible(true);

		return true;
	}
	return false;
}

void EnemyScene::onTouchEnded(Touch* touch, Event* event){}