//
// Created by laputa on 2017/6/9 0009.
//

#include "ClockLayer.h"

bool ClockLayer::init() {
    //画面尺寸
    Size viewSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    //返回菜单
    auto backLabel = Label::createWithTTF("BACK", "fonts/Marker Felt.ttf", 24);
    auto menuBackItem = MenuItemLabel::create(backLabel, CC_CALLBACK_1(ClockLayer::onClickBack, this));
    menuBackItem->setPosition(origin.x, origin.y);
    auto menu = Menu::create(menuBackItem, nullptr);
    menu->setPosition(origin.x + viewSize.width * 0.9f, origin.y + viewSize.height * 0.8f);
    this->addChild(menu);
    //表盘展示
    auto backgroundS = Sprite::create("res/background.jpg");
    backgroundS->setPosition(origin.x + viewSize.width / 2, origin.y + viewSize.height / 2);
    this->addChild(backgroundS, 0);
    this->hourS = Sprite::create("res/hour hand.png");
    hourS->setPosition(origin.x + viewSize.width / 2, origin.y + viewSize.height / 2);
    hourS->setAnchorPoint(Vec2(0.5, 0));
    hourS->setScale(0.5);
    this->addChild(hourS, 1);
    this->minuteS = Sprite::create("res/minute hand.png");
    minuteS->setPosition(origin.x + viewSize.width / 2, origin.y + viewSize.height / 2);
    minuteS->setAnchorPoint(Vec2(0.5, 0));
    minuteS->setScale(0.5);
    this->addChild(minuteS, 2);
    this->secondS = Sprite::create("res/second hand.png");
    secondS->setPosition(origin.x + viewSize.width / 2, origin.y + viewSize.height / 2);
    secondS->setAnchorPoint(Vec2(0.5, 0));
    secondS->setScale(0.5);
    this->addChild(secondS, 3);
    //初始偏转
    this->setTimeRotation();
    //定时器
    this->schedule(CC_SCHEDULE_SELECTOR(ClockLayer::onTimeChange), 1.0);

    return true;
}

void ClockLayer::onTimeChange(float dt) {
    CCLOG("onTimeChange param value:%f", dt);
    this->setTimeRotation();
}

//根据当前时间设置指针角度
void ClockLayer::setTimeRotation() const {
    //初始指针指向
    struct timeval now;
    gettimeofday(&now, NULL);
    struct tm *tm;
    tm = localtime(&now.tv_sec);
    //当前单位时间占满表盘时间的比例
    float hourPercent = (tm->tm_hour * 3600 + tm->tm_min * 60 + tm->tm_sec) * 1.0f / (3600 * 12);
    float minutePercent = (tm->tm_min * 60 + tm->tm_sec) * 1.0f / (3600);
    float secondPercent = (tm->tm_sec) * 1.0f / (60);
    hourS->setRotation(hourPercent * 360);
    minuteS->setRotation(minutePercent * 360);
    secondS->setRotation(secondPercent * 360);
    CCLOG("[localtime]hour:%d,minute:%d,second:%d,zone:%s", tm->tm_hour, tm->tm_min, tm->tm_sec, tm->tm_zone);
}

void ClockLayer::onClickBack(Ref *pSender) {
    CCLOG("onClickBack pSender ReferenceCount:%u", pSender->getReferenceCount());
    this->pSM->goOpenScene();
}