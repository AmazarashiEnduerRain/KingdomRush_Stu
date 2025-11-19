//
// Created by 20619 on 2025/11/19.
//
#include "ShopScene.h"
#include "Data/GameManager.h"
#
USING_NS_CC;

Scene *ShopScene::createScene() {
    auto scene = Scene::create();
    auto layer = ShopScene::create();
    scene->addChild(layer);
    return scene;
}

bool ShopScene::init() {
    if (!Layer::init()) return false;
    //获取屏幕尺寸
    size = Director::getInstance()->getVisibleSize(); //获取屏幕大小

    //文本数据直接初始化在数据源字符串中
    str_introduction[0] =
            "The big bad boy of\n bombs! You only need\n one of these to clear the\n battlefield and claim the\n spoils of war! JUST TELL\n US WHERE TO DROP IT!";
    str_introduction[1] =
            "FREEZE THE WORLE!\n\n The magic in this rod will\n freeze all baddies and\n prevent new ones from\n approaching.";
    str_introduction[2] =
            "Blast your enemies to\n pieces with these\n specially tailored\n gnome explosives.\n\n DESTRUCTION GUARANTEED.";
    str_introduction[3] = "This special concoction\n will freeze your enemies\n helpless in place for a\n while.";
    str_introduction[4] =
            "Magical hearts trapped\n in a box.\n\n break glass in an\n emergency to gain 5\n extra lives.";
    str_introduction[5] =
            "Leave nothing to chance.\n Bring extra gold to the\n battlefield!\n\n Each big worth 500\n gold pieces.";

    str_name[0] = "Boy";
    str_name[1] = "Ice";
    str_name[2] = "Bomb";
    str_name[3] = "Water";
    str_name[4] = "Heartbox";
    str_name[5] = "Money";

    str_gem[0] = 999;
    str_gem[1] = 250;
    str_gem[2] = 50;
    str_gem[3] = 50;
    str_gem[4] = 50;
    str_gem[5] = 500;

    label = Label::createWithTTF("", "SohoGothicProMedium.ttf", 24);
    label->setPosition(Point(680, 560));
    addChild(label, 1);
    label2 = Label::createWithTTF(" ", "SohoGothicProMedium.ttf", 24);
    label2->setPosition(Point(900, 545));
    addChild(label2, 1);
    label3 = Label::createWithTTF("", "SohoGothicProMedium.ttf", 12);
    label3->setPosition(Point(900, 440));
    addChild(label3, 1);

    for (int i = 0; i < 6; i++) {
        count[i] = UserDefault::getInstance()->getIntegerForKey(
            __String::createWithFormat(GameManager::getInstance()->SLOTX_SHOP, i)->getCString());
    }

    initBackpackIcon(); //左侧背包

    gem = UserDefault::getInstance()->getIntegerForKey(GameManager::getInstance()->SLOTX_GEM, 0);
    gemLabel = Label::createWithTTF(__String::createWithFormat("%d", gem)->getCString(), "SohoGothicProMedium.ttf", 30);
    gemLabel->setColor(Color3B::WHITE);
    gemLabel->setPosition(Point(size.width * 0.35, size.height * 0.92));
    addChild(gemLabel, 1);

    initPicture(); //商店图标和按钮

    auto listenerkeyPad = EventListenerKeyboard::create();
    listenerkeyPad->onKeyReleased = CC_CALLBACK_2(ShopScene::onKeyReleased, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listenerkeyPad, this);
    return true;
}

void ShopScene::initBackpackIcon() {
    float a[6] = {0.0f, 0.13f, 0.236f, 0.346f, 0.46f, 0.56f}; //偏移比例
    for (int i = 0; i < 6; i++) {
        //小图标创建（背包中的）
        auto backPackIcon = Sprite::createWithSpriteFrameName(
            __String::createWithFormat("inaps_backPackIcons_000%d.png", i + 1)->getCString());
        backPackIcon->setPosition(156, size.height * (0.72f - a[i]));
        addChild(backPackIcon, 3);

        if (count[i] == 0) backPackIcon->setVisible(false); //没有则隐藏

        auto countLabel = Label::createWithTTF(__String::createWithFormat("%d", count[i])->getCString(),
                                               "SohoGothicProMedium.ttf", 24);
        countLabel->setPosition(Point(137, size.height * (0.70f - a[i])));
        addChild(countLabel, 3);

        backpackIcons.pushBack(backPackIcon);
        countLabels.pushBack(countLabel);
    }
}

void ShopScene::initPicture() {
    auto size = Director::getInstance()->getVisibleSize(); //获取屏幕大小

    auto bgSprite = Sprite::createWithSpriteFrameName("inaps_BG.png");
    bgSprite->setPosition(Point(size.width * 0.5, size.height * 0.5));
    addChild(bgSprite, 0);

    board = Sprite::create();
    board->setPosition(Point(655, 440));
    addChild(board);

    auto shopIcon1 = ShopIcon::createIcon(1); //小男孩
    shopIcon1->setPosition(Point(640, 170));
    addChild(shopIcon1);
    auto shopIcon2 = ShopIcon::createIcon(2); //冰杖
    shopIcon2->setPosition(Point(830, 250));
    addChild(shopIcon2);
    auto shopIcon3 = ShopIcon::createIcon(3); //炸弹
    shopIcon3->setPosition(Point(485, 130));
    addChild(shopIcon3);
    auto shopIcon4 = ShopIcon::createIcon(4); //药瓶
    shopIcon4->setPosition(Point(385, 145));
    addChild(shopIcon4);
    auto shopIcon5 = ShopIcon::createIcon(5); //生命
    shopIcon5->setPosition(Point(280, 155));
    addChild(shopIcon5);
    auto shopIcon6 = ShopIcon::createIcon(6); //金币
    shopIcon6->setPosition(Point(800, 170));
    addChild(shopIcon6);
    shopIcons.pushBack(shopIcon1);
    shopIcons.pushBack(shopIcon2);
    shopIcons.pushBack(shopIcon3);
    shopIcons.pushBack(shopIcon4);
    shopIcons.pushBack(shopIcon5);
    shopIcons.pushBack(shopIcon6);

    //默认选中第三个
    shopIcon3->setGlowing();
    setBoard(3);

    //设置商品点击监听
    auto buttonListener = EventListenerTouchOneByOne::create();
    buttonListener->onTouchBegan = [&](Touch *touch, Event *event) {
        auto target = static_cast<ShopIcon *>(event->getCurrentTarget());
        Point locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size size = target->icon->getContentSize();
        Rect rect;
        if (target->type == 1)
            rect = Rect(0 - size.width / 4, 0 - size.height / 2, size.width / 2, size.height);
        else
            rect = Rect(0 - size.width / 4, 0 - size.height / 2, size.width / 2, size.height / 2);
        if (rect.containsPoint(locationInNode)) {
            setBoard(target->type); //黑板显示更新
            target->setScale(0.9f);
            return true;
        }
        return false;
    };
    buttonListener->onTouchEnded = [&](Touch *touch, Event *event) {
        auto target = static_cast<ShopIcon *>(event->getCurrentTarget());
        target->setScale(1.0f);
        for (int i = 0; i < 6; i++) shopIcons.at(i)->setNotGlowing();
        target->setGlowing();
    };
    buttonListener->setSwallowTouches(true);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener, shopIcon1);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon2);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon3);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon4);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon5);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon6);

    auto confirmButton = MenuItemSprite::create(Sprite::createWithSpriteFrameName("upgrades_buttons_0003.png"),
                                                Sprite::createWithSpriteFrameName("upgrades_buttons_0004.png"));
    confirmButton->setPosition(Point(size.width * 0.90, size.height * 0.10));
    confirmButton->setCallback([&](Ref *pSender) {
        UserDefault::getInstance()->setIntegerForKey(GameManager::getInstance()->SLOTX_GEM, gem);//按下确认按钮后，进行数据更新
        for (int i = 0; i < 6; i++) {
            UserDefault::getInstance()->setIntegerForKey(
                __String::createWithFormat(GameManager::getInstance()->SLOTX_SHOP, i)->getCString(), count[i]);
        }
        Director::getInstance()->popScene();
    });

    auto buyButton = MenuItemSprite::create(Sprite::createWithSpriteFrameName("inaps_buyButton_0001.png"),
                                            Sprite::createWithSpriteFrameName("inaps_buyButton_0002.png"));
    buyButton->setPosition(Point(780, 320));
    buyButton->setCallback([&](Ref *pSender) {
        for (int i = 0; i < 6; i++) {
            if (shopIcons.at(i)->glow->isVisible()) {
                buySth(i);
                break;
            }
        }
    });

    auto menu = Menu::create(confirmButton, buyButton, NULL); //实现切换
    menu->setPosition(Vec2::ZERO);
    addChild(menu, 1);
}

void ShopScene::buySth(int i) {
    if (gem < str_gem[i]) {
        auto bubbleNeedMore = Sprite::createWithSpriteFrameName("inaps_bubble_needMore.png");
        bubbleNeedMore->setVisible(true);
        bubbleNeedMore->setPosition(650, 430);
        addChild(bubbleNeedMore, 5);

        bubbleNeedMore->runAction(Sequence::create(
            FadeOut::create(3.0f),
            CallFuncN::create(CC_CALLBACK_0(Sprite::removeFromParent, bubbleNeedMore)), NULL));
    } else {
        gem = gem - str_gem[i];
        setBackpackIcon(i);//更新背包中的显示
        gemLabel->setString(__String::createWithFormat("%d", gem)->getCString());

        auto bubbleSprite = Sprite::createWithSpriteFrameName("inaps_bubble.png");
        bubbleSprite->setPosition(650, 430);
        addChild(bubbleSprite, 5);
        bubbleSprite->runAction(Sequence::create(
            FadeOut::create(3.0f),
            CallFuncN::create(CC_CALLBACK_0(Sprite::removeFromParent, bubbleSprite)), NULL));
    }
}

void ShopScene::setBackpackIcon(int i) {
    count[i]++;
    countLabels.at(i)->setString(__String::createWithFormat("%d", count[i])->getCString());
    if (count[i] > 0) backpackIcons.at(i)->setVisible(true);
}

void ShopScene::setBoard(int type) {
    board->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(
        __String::createWithFormat("inaps_boardDrawings_000%d.png", type)->getCString()));
    label3->setString(str_introduction[type - 1]);
    label2->setString(__String::createWithFormat("%d", str_gem[type - 1])->getCString());
    label->setString(str_name[type - 1]);
}

void ShopScene::onKeyReleased(EventKeyboard::KeyCode keycode, Event *event) {
    switch (keycode) {
        case EventKeyboard::KeyCode::KEY_BACK: //返回键听
            Director::getInstance()->popScene();
            break;
        case EventKeyboard::KeyCode::KEY_MENU: //菜单监听
            break;
        case::EventKeyboard::KeyCode::KEY_HOME:
            break;
        default:
            break;
    }
}
