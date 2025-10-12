#include "BaseTower.h"
#include "Terrain.h"
#include "Map/BaseMap.h"
#include "Data/GameManager.h"

BaseTower::BaseTower(): isUpdateMenuShown(false), nearestMonster(nullptr), terrain(nullptr)
{}

BaseTower::~BaseTower() {}

bool BaseTower::init() {
    if (!Sprite::init()) return false;
    isUpdateMenuShown = false;
    return true;
}

bool BaseTower::onTouchBegan(Touch *touch, Event *event) {
    return true;
}

void BaseTower::onTouchEnded(Touch *touch, Event *event) {
    auto target = static_cast<Sprite*>(event->getCurrentTarget());
    Point locationInNode = target->convertTouchToNodeSpace(touch);
    Size size = target->getContentSize();
    Rect rect = Rect(0, 0, size.width, size.height);

    if (rect.containsPoint(locationInNode)) {
        auto map = static_cast<BaseMap*>(this->getParent()->getParent());
        if (map && map->playerState) {
            map->playerState->showTowerInfo(getTowerType());
        }

        if (isUpdateMenuShown) hideUpdateMenu();
        else showUpdateMenu();
    }
}

void BaseTower::showTowerInfo() {}

void BaseTower::sellTower() {
    auto customTerrain = static_cast<CustomTerrain*>(this->getParent());
    if (customTerrain && customTerrain->terrain) {
        customTerrain->terrain->setVisible(true);
    }
    removeTower();
}

void BaseTower::removeTower() {
    auto map = static_cast<BaseMap*>(this->getParent()->getParent());
    if (map && map->playerState) {
        map->playerState->removeTowerInfo();
    }

    auto customTerrain = static_cast<CustomTerrain*>(this->getParent());
    if (customTerrain) customTerrain->smokeEffect();

    this->unscheduleAllCallbacks();
    this->removeAllChildren();
    this->removeFromParent();
}

void BaseTower::setListener() {
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(BaseTower::onTouchBegan, this);
    listener->onTouchEnded = CC_CALLBACK_2(BaseTower::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, terrain);
}

void BaseTower::checkNearestMonster() {
    auto gameManager = GameManager::getInstance();
    auto& monsterVector = gameManager->monsterVector;

    float currMinDistant = this->getScope();
    BaseMonster *monsterTemp = nullptr;

    for (auto monster : monsterVector) {
        if (monster && monster->baseSprite) {
            float distance = this->getParent()->getPosition().getDistance(monster->baseSprite->getPosition());

            if (distance < currMinDistant && monster->getAttackByTower()) {
                currMinDistant = distance;
                monsterTemp = monster;
            }
        }
    }
    nearestMonster = monsterTemp;
}

void BaseTower::hideUpdateMenu() {
    if (isUpdateMenuShown) {
        auto map = static_cast<BaseMap*>(this->getParent()->getParent());
        if (map && map->mTouchLayer) {
            map->mTouchLayer->removeChildByTag(this->getTag() + 100);
        }
        isUpdateMenuShown = false;
    }
}