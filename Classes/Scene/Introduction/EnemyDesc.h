//
// Created by 20619 on 2025/11/20.
//

#ifndef KINGDOMRUSH_STU_ENEMYDESC_H
#define KINGDOMRUSH_STU_ENEMYDESC_H

#include "cocos2d.h"
#include <string>
USING_NS_CC;

class EnemyDesc : public Sprite{
public:
    virtual bool myinit(std::string name);
    static EnemyDesc* createEnemyDesc(std::string name);
    CREATE_FUNC(EnemyDesc);

    Sprite* enemyDescPic;
    std::string enemyThumbFileName;
    std::string enemyDescFileName;
    int id;
    std::string enemyName;
    std::string enemyDesc;

    std::string bloodValue;
    std::string attackValue;
    std::string defenseValue;
    std::string magicDefenseValue;
    std::string movementSpeed;
    std::string lifeNumber;
    std::string note;

    void setData(
                Sprite* enemyDescPic,
                int id,const std::string& enemyThumbFileName,const std::string& enemyDescFileName,
                const std::string& enemyName,const std::string& enemyDesc,
                const std::string& bloodValue,const std::string& attackValue,const std::string& defenseValue,
                const std::string& magicDefenseValue,const std::string& movementSpeed,const std::string& lifeNumber,
                const std::string& note);
};


#endif //KINGDOMRUSH_STU_ENEMYDESC_H