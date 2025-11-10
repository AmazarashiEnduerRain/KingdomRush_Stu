//
// Created by 20619 on 2025/11/10.
//
#include "Data/GameManager.h"
#include "Bullet/Smoke.h"

bool Smoke::init(){
    if (!Sprite::init()) return false;
    return true;
}

void Smoke::fadeSmoke(Animation* animation,float time){
    runAction(Sequence::create(Animate::create(animation),
        DelayTime::create(time),
        CallFuncN::create(CC_CALLBACK_0(Smoke::remove, this)),NULL));
}

void Smoke::remove(){ this->removeFromParent();}