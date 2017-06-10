//
// Created by laputa on 2017/6/9 0009.
//

#ifndef PROJ_ANDROID_STUDIO_CLOCKLAYER_H
#define PROJ_ANDROID_STUDIO_CLOCKLAYER_H

#include "cocos2d.h"
#include "SceneManager.h"

USING_NS_CC;

class ClockLayer : public Layer {
public:
    SceneManager *pSM = nullptr;
public:
    CREATE_FUNC(ClockLayer);

    virtual bool init();
};


#endif //PROJ_ANDROID_STUDIO_CLOCKLAYER_H
