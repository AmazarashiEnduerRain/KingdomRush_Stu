//
// Created by 20619 on 2025/11/14.
// 呼吸动画精灵

#ifndef KINGDOMRUSH_STU_RESPIRATIONSPRITE_H
#define KINGDOMRUSH_STU_RESPIRATIONSPRITE_H

#include "cocos2d.h"
USING_NS_CC;

class RespirationSprite : public Sprite{
public:
    virtual bool RespirationInit(const std::string SpriteFrameName);
    CREATE_FUNC(RespirationSprite);
    static RespirationSprite* createRespirationSprite(const std::string SpriteFrameName);
private:
    void startRespiration(float dt);
};

#endif //KINGDOMRUSH_STU_RESPIRATIONSPRITE_H