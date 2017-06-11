//
// Created by laputa on 2017/6/9 0009.
//

#include "OpenLayer.h"

bool OpenLayer::init() {
    //画面尺寸
    Size viewSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    //add lable
    auto gameLabel = Label::createWithTTF("Clock Game", "fonts/Marker Felt.ttf", 48);
    gameLabel->setPosition(origin.x + viewSize.width / 2, origin.y + viewSize.height * 4 / 5);
    this->addChild(gameLabel, 0);
    //添加菜单
    auto startLabel = Label::createWithTTF("START", "fonts/Marker Felt.ttf", 36);
    auto menuStartItem = MenuItemLabel::create(startLabel, CC_CALLBACK_1(OpenLayer::onClickMenu, this));
    menuStartItem->setPosition(origin.x + viewSize.width / 2, origin.y + viewSize.height * 2 / 5);
    menuStartItem->setTag(1001);

    auto exitLabel = Label::createWithTTF("EXIT", "fonts/Marker Felt.ttf", 36);
    auto menuExitItem = MenuItemLabel::create(exitLabel, CC_CALLBACK_1(OpenLayer::onClickMenu, this));
    menuExitItem->setPosition(origin.x + viewSize.width / 2, origin.y + viewSize.height / 5);
    menuExitItem->setTag(1002);

    auto menu = Menu::create(menuStartItem, menuExitItem, nullptr);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    return true;
}

//This is a callback method for menu
void OpenLayer::onClickMenu(Ref *pSender) {
    CCLOG("OpenLayer::onClickMenu");
    auto menuItem = (Menu *) pSender;
    switch (menuItem->getTag()) {
        case 1001: {
            this->pSM->goClockScene();
            break;
        }
        case 1002: {
            Director::getInstance()->end();
            break;
        }
        default: {
            break;
        }
    }
}