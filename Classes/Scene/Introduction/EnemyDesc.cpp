//
// Created by 20619 on 2025/11/20.
//
#include "EnemyDesc.h"
USING_NS_CC;

EnemyDesc* EnemyDesc::createEnemyDesc(std::string name){
    auto enemyDesc = new EnemyDesc();
    if(enemyDesc && enemyDesc->myinit(name)){
        enemyDesc->autorelease();
        return enemyDesc;
    }
    CC_SAFE_DELETE(enemyDesc);
    return NULL;
}

bool EnemyDesc::myinit(std::string name){
    if(!Sprite::init()) return false;
    enemyDescPic = Sprite::createWithSpriteFrameName(name);
    addChild(enemyDescPic);

    return true;
}

void EnemyDesc::setData(
                Sprite* enemyDescPic,
                int id,
                const std::string& enemyThumbFileName,
                const std::string& enemyDescFileName,
                const std::string& enemyName,
                const std::string& enemyDesc,
                const std::string& bloodValue,
                const std::string& attackValue,
                const std::string& defenseValue,
                const std::string& magicDefenseValue,
                const std::string& movementSpeed,
                const std::string& lifeNumber,
                const std::string& note){
    this->enemyDescPic = enemyDescPic;
    this->id = id;
    this->enemyThumbFileName = enemyThumbFileName;
    this->enemyDescFileName = enemyDescFileName;
    this->enemyName = enemyName;
    this->enemyDesc = enemyDesc;
    this->bloodValue = bloodValue;
    this->attackValue  = attackValue;
    this->defenseValue = defenseValue;
    this->magicDefenseValue = magicDefenseValue;
    this->movementSpeed = movementSpeed;
    this->lifeNumber = lifeNumber;
    this->note = note;
}