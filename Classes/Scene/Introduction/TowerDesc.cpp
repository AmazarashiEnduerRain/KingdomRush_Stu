//
// Created by 20619 on 2025/11/20.
//

#include "TowerDesc.h"

USING_NS_CC;

TowerDesc* TowerDesc::createTowerDesc(std::string name){
    auto towerDesc = new TowerDesc();
    if(towerDesc && towerDesc->myinit(name)){
        towerDesc->autorelease();
        return towerDesc;
    }
    CC_SAFE_DELETE(towerDesc);
    return NULL;
}

bool TowerDesc::myinit(std::string name){
    if(!Sprite::init()) return false;
    towerDescPic = Sprite::createWithSpriteFrameName(name);
    addChild(towerDescPic);

    return true;
}

void TowerDesc::setData(
                Sprite* towerDescPic,
                const std::string& towerThumbFileName,
                const std::string& towerDescFileName,
                int id,
                const std::string& towerName,
                const std::string& attackSpeed,
                const std::string& attackValue,
                const std::string& attackRange,
                const std::string& note){
    this->towerDescPic = towerDescPic;
    this->towerThumbFileName = towerThumbFileName;
    this->towerDescFileName = towerDescFileName;
    this->id = id;
    this->towerName = towerName;
    this->attackSpeed = attackSpeed;
    this->attackValue  = attackValue;
    this->attackRange = attackRange;
    this->note = note;
}
