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
    Sprite *hourS = nullptr;
    Sprite *minuteS = nullptr;
    Sprite *secondS = nullptr;
    SceneManager *pSM = nullptr;
public:
    CREATE_FUNC(ClockLayer);

    virtual bool init();

    void onTimeChange(float dt);

    void onClickBack(Ref *pSender);

    void setTimeRotation() const;
};


#endif //PROJ_ANDROID_STUDIO_CLOCKLAYER_H
