LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d/cocos)
$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d/cocos/audio/include)

LOCAL_MODULE := MyGame_shared

LOCAL_MODULE_FILENAME := libMyGame

#初始提供的方式,需要声明每一个文件
#LOCAL_SRC_FILES := hellocpp/main.cpp \
#                    ../../../Classes/AppDelegate.cpp \
#                    ../../../Classes/LoadLayer.cpp \
#                    ../../../Classes/OpenLayer.cpp \
#                    ../../../Classes/ClockLayer.cpp \
#                    ../../../Classes/SceneManager.cpp \


#新方式,直接获取目录下的所有cpp文件
#MY_CPP_LIST := $(wildcard $(LOCAL_PATH)/../../../Classes/*.cpp)
#LOCAL_SRC_FILES := hellocpp/main.cpp \
#LOCAL_SRC_FILES += $(MY_CPP_LIST:$(LOCAL_PATH)/%=%)

#LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../../Classes

#移动源码文件目录
MY_CPP_LIST := $(wildcard $(LOCAL_PATH)/hellocpp/*.cpp)
LOCAL_SRC_FILES := $(MY_CPP_LIST:$(LOCAL_PATH)/%=%)

LOCAL_C_INCLUDES := $(LOCAL_PATH)/hellocpp

# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END


LOCAL_STATIC_LIBRARIES := cocos2dx_static

# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)

# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END
