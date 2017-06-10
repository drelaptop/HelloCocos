//
// Created by laputa on 2017/6/9 0009.
//

#ifndef PROJ_ANDROID_STUDIO_SCENEMANAGER_H
#define PROJ_ANDROID_STUDIO_SCENEMANAGER_H

#include "cocos2d.h"

USING_NS_CC;

class SceneManager {
public:
    Scene * loadScene = nullptr;
    Scene * openScene = nullptr;
    Scene * clockScene = nullptr;
public:
    void createLoadScene();
    void goOpenScene();
    void goClockScene();
};


#endif //PROJ_ANDROID_STUDIO_SCENEMANAGER_H
