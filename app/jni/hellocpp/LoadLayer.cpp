//
// Created by laputa on 2017/6/9 0009.
//

#include "LoadLayer.h"

bool LoadLayer::init() {
    Size viewSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    //Show Loading...
    auto label = Label::createWithTTF("Loading...", "fonts/Marker Felt.ttf", 48);
    label->setPosition(origin.x + viewSize.width / 2, origin.y + viewSize.height / 2);
    this->addChild(label, 1);
    scheduleOnce(CC_SCHEDULE_SELECTOR(LoadLayer::onScheduleOnce), 2.0);
    return true;
}

void LoadLayer::onScheduleOnce(float dt) {
    this->pSM->goOpenScene();
}