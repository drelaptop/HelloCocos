//
// Created by laputa on 2017/6/9 0009.
//

#include "SceneManager.h"
#include "LoadLayer.h"
#include "OpenLayer.h"
#include "ClockLayer.h"

void SceneManager::createLoadScene() {
    this->loadScene = Scene::create();
    auto loadLayer = LoadLayer::create();
    loadLayer->pSM = this;
    this->loadScene->addChild(loadLayer);
}

void SceneManager::goOpenScene() {
    this->openScene = Scene::create();
    auto openLayer = OpenLayer::create();
    openLayer->pSM = this;
    this->openScene->addChild(openLayer);
    Director::getInstance()->replaceScene(this->openScene);
}

void SceneManager::goClockScene() {
    this->clockScene = Scene::create();
    auto clockLayer = ClockLayer::create();
    clockLayer->pSM = this;
    this->clockScene->addChild(clockLayer);
    Director::getInstance()->replaceScene(this->clockScene);
}
