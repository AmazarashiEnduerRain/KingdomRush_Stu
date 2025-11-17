//
// Created by 20619 on 2025/10/25.
//
#include "Bullet.h"

Bullet::Bullet()
:sprite(NULL),maxForce(0),bulletScope(0){
}

Bullet::~Bullet(){}

bool Bullet::init(){
    if (!Sprite::init()) return false;
    return true;
}