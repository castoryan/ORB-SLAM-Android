LOCAL_PATH := $(call my-dir)


#### liblibtiff.a ####
include $(CLEAR_VARS)
LOCAL_MODULE := liborb
LOCAL_SRC_FILES := ./lib/liborbslam.so
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/include
LOCAL_EXPORT_C_INCLUDES += $(LOCAL_PATH)/ORB_SLAM2/include
LOCAL_EXPORT_C_INCLUDES += $(LOCAL_PATH)/Thirdparty/DBoW2
LOCAL_EXPORT_C_INCLUDES += $(LOCAL_PATH)/Thirdparty/g2o
include $(PREBUILT_SHARED_LIBRARY)

#### 主要文件 test.cpp ####

include $(CLEAR_VARS)
LOCAL_MODULE := mono
LOCAL_CPPFLAGS  += -std=c++11
LOCAL_LDLIBS    += -llog -landroid -lEGL -lGLESv1_CM -lz

LOCAL_SHARED_LIBRARIES += liborb

LOCAL_SRC_FILES += ./mono_camera.cpp

#LOCAL_ALLOW_UNDEFINED_SYMBOLS := true

include $(BUILD_SHARED_LIBRARY)

####################################################################################################