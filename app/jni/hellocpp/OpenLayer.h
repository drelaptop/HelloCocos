//
// Created by laputa on 2017/6/9 0009.
//

#ifndef PROJ_ANDROID_STUDIO_OPENLAYER_H
#define PROJ_ANDROID_STUDIO_OPENLAYER_H

#include "cocos2d.h"
#include "SceneManager.h"

USING_NS_CC;

class OpenLayer : public Layer {
public:
    SceneManager *pSM = nullptr;
public:
    CREATE_FUNC(OpenLayer);

    virtual bool init();

    void onClickMenu(Ref *pSender);

};


#endif //PROJ_ANDROID_STUDIO_OPENLAYER_H
