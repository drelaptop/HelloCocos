//
// Created by laputa on 2017/6/9 0009.
//

#ifndef PROJ_ANDROID_STUDIO_LOADLAYER_H
#define PROJ_ANDROID_STUDIO_LOADLAYER_H

#include "cocos2d.h"
#include "SceneManager.h"

USING_NS_CC;

class LoadLayer : public Layer {
public:
    SceneManager *pSM = nullptr;
public:
    CREATE_FUNC(LoadLayer);

    virtual bool init();

    void onScheduleOnce(float dt);
};


#endif //PROJ_ANDROID_STUDIO_LOADLAYER_H
