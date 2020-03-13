LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

COCOS2D_ROOT := ../../../cocos2d

LOCAL_MODULE := paysdk_bridge

ifeq ($(USE_ARM_MODE),1)
LOCAL_ARM_MODE := arm
endif

LOCAL_SRC_FILES := 	../../../Classes/C2DXPaySDK/C2DXPaySDK.cpp \
                    ../../../Classes/C2DXPaySDK/Android/C2DXAndroidPaySDK.cpp \
                    ../../../Classes/C2DXPaySDK/Android/C2DXAndroidPayApi.cpp \
                    ../../../Classes/C2DXPaySDK/Android/C2DXAndroidOrder.cpp \
                    ../../../Classes/C2DXPaySDK/Android/C2DXCxxJavaObject.cpp \
                    ../../../Classes/C2DXPaySDK/Android/C2DXAndroidOnPayListener.cpp \
                    ../../../Classes/C2DXPaySDK/Android/C2DXAndroidPayResult.cpp \
                    ../../../Classes/C2DXPaySDK/Android/com_mob_paysdk_cocos2dx_OnPayListener.cpp


LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(COCOS2D_ROOT)/cocos \
					$(LOCAL_PATH)/$(COCOS2D_ROOT)/cocos/platform/android \
					$(LOCAL_PATH)/../../../Classes \
					$(LOCAL_PATH)/../../../Classes/C2DXPaySDK \
					$(LOCAL_PATH)/../../../Classes/C2DXPaySDK/Android \
					$(LOCAL_PATH)/../../../Classes/C2DXPaySDK/Android/JSON \
                    $(LOCAL_PATH)/../../../Classes/C2DXPaySDK/Android/JSON/cJSON
					
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/../../../Classes/C2DXPaySDK \
					$(LOCAL_PATH)/../../../Classes/C2DXPaySDK/Android \
					$(LOCAL_PATH)/../../../Classes/C2DXPaySDK/Android/JSON \
                    $(LOCAL_PATH)/../../../Classes/C2DXPaySDK/Android/JSON/cJSON
					

include $(BUILD_STATIC_LIBRARY)

