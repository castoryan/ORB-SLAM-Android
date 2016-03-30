LOCAL_PATH := $(call my-dir)


###########################    import opencv     #############################


#### libopencv_core.a ####
include $(CLEAR_VARS)
LOCAL_MODULE := libopencv_core
LOCAL_SRC_FILES := ./lib/opencv/libopencv_core.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/include
include $(PREBUILT_STATIC_LIBRARY)

#### libopencv_features2d.a ####
include $(CLEAR_VARS)
LOCAL_MODULE := opencv_features2d
LOCAL_SRC_FILES := ./lib/opencv/libopencv_features2d.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/include
include $(PREBUILT_STATIC_LIBRARY)

#### libopencv_highgui.a ####
include $(CLEAR_VARS)
LOCAL_MODULE := opencv_highgui
LOCAL_SRC_FILES := ./lib/opencv/libopencv_highgui.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/include
include $(PREBUILT_STATIC_LIBRARY)

#### libopencv_flann.a ####
include $(CLEAR_VARS)
LOCAL_MODULE := opencv_flann
LOCAL_SRC_FILES := ./lib/opencv/libopencv_flann.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/include
include $(PREBUILT_STATIC_LIBRARY)

#### libopencv_imgproc.a ####
include $(CLEAR_VARS)
LOCAL_MODULE := opencv_imgproc
LOCAL_SRC_FILES := ./lib/opencv/libopencv_imgproc.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/include
include $(PREBUILT_STATIC_LIBRARY)

#### libopencv_calib3d.a ####
include $(CLEAR_VARS)
LOCAL_MODULE := opencv_calib3d
LOCAL_SRC_FILES := ./lib/opencv/libopencv_calib3d.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/include
include $(PREBUILT_STATIC_LIBRARY)


#### libtbb.a ####
include $(CLEAR_VARS)
LOCAL_MODULE := tbb
LOCAL_SRC_FILES := ./lib/opencv/3rdparty/libtbb.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/include
include $(PREBUILT_STATIC_LIBRARY)

#### libIlmImf.a ####
include $(CLEAR_VARS)
LOCAL_MODULE := IlmImf
LOCAL_SRC_FILES := ./lib/opencv/3rdparty/libIlmImf.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/include
include $(PREBUILT_STATIC_LIBRARY)

#### liblibjasper.a ####
include $(CLEAR_VARS)
LOCAL_MODULE := libjasper
LOCAL_SRC_FILES := ./lib/opencv/3rdparty/liblibjasper.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/include
include $(PREBUILT_STATIC_LIBRARY)

#### liblibjpeg.a ####
include $(CLEAR_VARS)
LOCAL_MODULE := libjpeg
LOCAL_SRC_FILES := ./lib/opencv/3rdparty/liblibjpeg.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/include
include $(PREBUILT_STATIC_LIBRARY)

#### liblibpng.a ####
include $(CLEAR_VARS)
LOCAL_MODULE := libpng
LOCAL_SRC_FILES := ./lib/opencv/3rdparty/liblibpng.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/include
include $(PREBUILT_STATIC_LIBRARY)

#### liblibtiff.a ####
include $(CLEAR_VARS)
LOCAL_MODULE := libtiff
LOCAL_SRC_FILES := ./lib/opencv/3rdparty/liblibtiff.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/include
include $(PREBUILT_STATIC_LIBRARY)






#### 主要文件 test.cpp ####
ThirdParty_PATH := ./Thirdparty
ORB_SLAM2_PATH := ./ORB_SLAM2/src

include $(CLEAR_VARS)
LOCAL_MODULE := mono
LOCAL_CPPFLAGS  += -std=c++11
LOCAL_LDLIBS    += -llog -landroid -lEGL -lGLESv1_CM -lz




###############  SHARED_OPENCV  ################

#LOCAL_SHARED_LIBRARIES +=  g2o_cli
#LOCAL_SHARED_LIBRARIES +=  g2o_core


LOCAL_SHARED_LIBRARIES += libopencv_features2d
LOCAL_SHARED_LIBRARIES += libopencv_highgui
LOCAL_SHARED_LIBRARIES += libopencv_imgproc
LOCAL_SHARED_LIBRARIES += libopencv_core
LOCAL_SHARED_LIBRARIES += libopencv_flann
LOCAL_SHARED_LIBRARIES += libopencv_calib3d

LOCAL_SHARED_LIBRARIES += libIlmlmf
LOCAL_SHARED_LIBRARIES += liblibjasper
LOCAL_SHARED_LIBRARIES += liblibjpeg
LOCAL_SHARED_LIBRARIES += liblibpng
LOCAL_SHARED_LIBRARIES += liblibtiff
LOCAL_SHARED_LIBRARIES += libtbb

LOCAL_C_INCLUDES := $(LOCAL_PATH)/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/ORB_SLAM2/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/ORB_SLAM2/include/Thirdparty

FILE_LIST00 := $(wildcard $(ThirdParty_PATH)/DBoW2/DBoW2/*.cpp)
FILE_LIST01 := $(wildcard $(ThirdParty_PATH)/DBoW2/DUtils/*.cpp)

LOCAL_SRC_FILES :=  $(ThirdParty_PATH)/DBoW2/DBoW2/BowVector.cpp  $(ThirdParty_PATH)/DBoW2/DBoW2/FeatureVector.cpp\
                    $(ThirdParty_PATH)/DBoW2/DBoW2/FORB.cpp  $(ThirdParty_PATH)/DBoW2/DBoW2/ScoringObject.cpp\
                    $(ThirdParty_PATH)/DBoW2/DUtils/Random.cpp $(ThirdParty_PATH)/DBoW2/DUtils/Timestamp.cpp\
                    #$(FILE_LIST00:$(LOCAL_PATH)/%=%) \
                    #$(FILE_LIST01:$(LOCAL_PATH)/%=%) \

FILE_LIST1 := $(wildcard $(ThirdParty_PATH)/g2o/g2o/core/*.cpp)
FILE_LIST2 := $(wildcard $(ThirdParty_PATH)/g2o/g2o/stuff/*.cpp)
FILE_LIST3 := $(wildcard $(ThirdParty_PATH)/g2o/g2o/types/*.cpp)


LOCAL_SRC_FILES +=  $(ThirdParty_PATH)/g2o/g2o/core/batch_stats.cpp  $(ThirdParty_PATH)/g2o/g2o/core/cache.cpp\
                    $(ThirdParty_PATH)/g2o/g2o/core/estimate_propagator.cpp  $(ThirdParty_PATH)/g2o/g2o/core/factory.cpp\
                    $(ThirdParty_PATH)/g2o/g2o/core/hyper_dijkstra.cpp  $(ThirdParty_PATH)/g2o/g2o/core/hyper_graph.cpp\
                    $(ThirdParty_PATH)/g2o/g2o/core/hyper_graph_action.cpp $(ThirdParty_PATH)/g2o/g2o/core/jacobian_workspace.cpp\
                    $(ThirdParty_PATH)/g2o/g2o/core/marginal_covariance_cholesky.cpp\
                    $(ThirdParty_PATH)/g2o/g2o/core/matrix_structure.cpp  $(ThirdParty_PATH)/g2o/g2o/core/optimizable_graph.cpp\
                    $(ThirdParty_PATH)/g2o/g2o/core/optimization_algorithm.cpp  $(ThirdParty_PATH)/g2o/g2o/core/optimization_algorithm_dogleg.cpp\
                    $(ThirdParty_PATH)/g2o/g2o/core/optimization_algorithm_factory.cpp\
                    $(ThirdParty_PATH)/g2o/g2o/core/optimization_algorithm_gauss_newton.cpp\
                    $(ThirdParty_PATH)/g2o/g2o/core/optimization_algorithm_levenberg.cpp\
                    $(ThirdParty_PATH)/g2o/g2o/core/optimization_algorithm_with_hessian.cpp\
                    $(ThirdParty_PATH)/g2o/g2o/core/parameter.cpp  $(ThirdParty_PATH)/g2o/g2o/core/parameter_container.cpp\
                    $(ThirdParty_PATH)/g2o/g2o/core/robust_kernel.cpp  $(ThirdParty_PATH)/g2o/g2o/core/robust_kernel_factory.cpp\
                    $(ThirdParty_PATH)/g2o/g2o/core/robust_kernel_impl.cpp  $(ThirdParty_PATH)/g2o/g2o/core/solver.cpp\
                    $(ThirdParty_PATH)/g2o/g2o/core/sparse_optimizer.cpp\
                    $(ThirdParty_PATH)/g2o/g2o/stuff/os_specific.c  $(ThirdParty_PATH)/g2o/g2o/stuff/property.cpp\
                    $(ThirdParty_PATH)/g2o/g2o/stuff/string_tools.cpp  $(ThirdParty_PATH)/g2o/g2o/stuff/timeutil.cpp\
                    $(ThirdParty_PATH)/g2o/g2o/types/types_sba.cpp  $(ThirdParty_PATH)/g2o/g2o/types/types_seven_dof_expmap.cpp\
                    $(ThirdParty_PATH)/g2o/g2o/types/types_six_dof_expmap.cpp\
                    #$(FILE_LIST1:$(LOCAL_PATH)/%=%) \
                    #$(FILE_LIST2:$(LOCAL_PATH)/%=%) \
                    #$(FILE_LIST3:$(LOCAL_PATH)/%=%) \

LOCAL_SRC_FILES +=  $(ORB_SLAM2_PATH)/System.cc $(ORB_SLAM2_PATH)/Sim3Solver.cc\
                    $(ORB_SLAM2_PATH)/Tracking.cc $(ORB_SLAM2_PATH)/FrameDrawer.cc $(ORB_SLAM2_PATH)/Converter.cc \
                    $(ORB_SLAM2_PATH)/Frame.cc  $(ORB_SLAM2_PATH)/Initializer.cc  $(ORB_SLAM2_PATH)/KeyFrame.cc  \
                    $(ORB_SLAM2_PATH)/LocalMapping.cc  $(ORB_SLAM2_PATH)/LoopClosing.cc  $(ORB_SLAM2_PATH)/Map.cc  \
                    $(ORB_SLAM2_PATH)/MapPoint.cc  $(ORB_SLAM2_PATH)/Optimizer.cc $(ORB_SLAM2_PATH)/KeyFrameDatabase.cc\
                    $(ORB_SLAM2_PATH)/ORBextractor.cc  $(ORB_SLAM2_PATH)/ORBmatcher.cc  $(ORB_SLAM2_PATH)/PnPsolver.cc  \

                    #$(ORB_SLAM2_PATH)/Viewer.cc $(ORB_SLAM2_PATH)/MapDrawer.cc  \

LOCAL_SRC_FILES += ./mono_camera.cpp

#LOCAL_ALLOW_UNDEFINED_SYMBOLS := true

include $(BUILD_SHARED_LIBRARY)

####################################################################################################
#### 主要文件 mono_camera.cpp ####

#include $(CLEAR_VARS)
#LOCAL_MODULE := mono
#LOCAL_CPPFLAGS  += -std=c++11
#LOCAL_LDLIBS    += -llog -landroid -lEGL -lGLESv1_CM -lz

#LOCAL_SHARED_LIBRARIES += liborb

#LOCAL_SRC_FILES += ./mono_camera.cpp

#LOCAL_ALLOW_UNDEFINED_SYMBOLS := true

#include $(BUILD_SHARED_LIBRARY)