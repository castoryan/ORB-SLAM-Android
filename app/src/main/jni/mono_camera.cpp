/** Project: ORB-SLAM-Android.
 *  For more information see <https://github.com/castoryan/ORB-SLAM-Android>
 *
 *  The original work was done by Raúl Mur-Artal <raulmur at unizar dot es> (University of Zaragoza)
 *  For more information see <https://github.com/raulmur/ORB_SLAM2>
 *
 *  filename: mono_camera.cpp
 *
 *  Created or Edited by Qinrui Yan on 30/Oct/2016.
 *  E-mail: castoryan1991@gmail.com
 *  Copyright © 2016 Qinrui Yan. All rights reserved.
 */

#include <android/log.h>
#include <opencv2/core/core.hpp>
#include "jni.h"
#include "System.h"
#include "com_example_castoryan_orb_MyNDK.h"
#include <typeinfo>
#include <mutex>
#include <thread>

#define TAG    "orb_debug_inmono"
#define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,TAG,__VA_ARGS__)


static std::chrono::steady_clock::time_point t0;
static double ttrack=0;
/*
 * Class:     com_example_castoryan_orb_MyNDK
 * Method:    test
 * Signature: (II)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_example_castoryan_orb_MyNDK_test
        (JNIEnv *env, jobject obj, jint a, jint b){

}

/*
 * Class:     com_example_castoryan_orb_MyNDK
 * Method:    System
 * Signature: (Ljava/lang/String;Ljava/lang/String;IZ)V
 */
JNIEXPORT jlong JNICALL Java_com_example_castoryan_orb_MyNDK_System
        (JNIEnv *env, jobject obj, jstring vocfile, jstring settingfile, jint sensor, jboolean useviewer, jlong imgaddr, jint mode){

    static ORB_SLAM2::System* sy;
    if(mode == 1) {
        const char *voc = env->GetStringUTFChars(vocfile, 0);
        const char *set = env->GetStringUTFChars(settingfile, 0);
        LOGD("Initializing mono: success in = %s", voc);
        LOGD("Initializing mono: success in = %s", set);
        LOGD("Initializing mono: ORB_SLAM2::System::MONOCULAR = %d", ORB_SLAM2::System::MONOCULAR);


        static ORB_SLAM2::System sy2(voc, set, ORB_SLAM2::System::MONOCULAR, false);
        t0 = std::chrono::steady_clock::now();
        sy = &sy2;
    }


    if(mode == 2){

        const cv::Mat *im = (cv::Mat *) imgaddr;
        std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
        ttrack = std::chrono::duration_cast < std::chrono::duration < double >> (t1 - t0).count();
        LOGD("Tracking mono: ttrack is %f", ttrack);

        sy->TrackMonocular(*im, ttrack);
    }

    if(mode == 3) {

        sy->Shutdown();
        sy->Reset();
        LOGD("Shuting mono: The system has been shut down");
    }

    const jlong slamaddr = 0;// = &SLAM;
    return slamaddr;
}

/*
 * Class:     com_example_castoryan_orb_MyNDK
 * Method:    TrackMonocular
 * Signature: (JD)J
 */
JNIEXPORT jlong JNICALL Java_com_example_castoryan_orb_MyNDK_TrackMonocular
        (JNIEnv * env, jobject obj, jlong addr, jdouble time){

        return 0;
}


/*
 * Class:     com_example_castoryan_orb_MyNDK
 * Method:    Shutdown
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_example_castoryan_orb_MyNDK_Shutdown
        (JNIEnv *env, jobject obj,jlong addr){

}



