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
        //const int sen = sensor;
        //const void* view= useviewer;
        /*ORB_SLAM2::System SLAM(vocfile, setfile, sen, view);*/
        LOGD("Initializing mono: success in = %s", voc);
        LOGD("Initializing mono: success in = %s", set);
        LOGD("Initializing mono: ORB_SLAM2::System::MONOCULAR = %d", ORB_SLAM2::System::MONOCULAR);
        //LOGD("Initializing mono: thread id is %lu", std::this_thread::get_id());
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
/*
    LOGD("Initializing mono: sy2 thread id is %lu",std::this_thread::get_id());
    LOGD("Initializing mono: sy2 mSensor is %d", sy2.mSensor);
    LOGD("Initializing mono: sy2 ActivateMode %d",sy2.mbActivateLocalizationMode);
    LOGD("Initializing mono: sy2 DeActivateMode %d",sy2.mbDeactivateLocalizationMode);
    LOGD("Initializing mono: sy2 mbReset %d",sy2.mbReset);

    LOGD("Initializing mono: sy mSensor is %d", sy->mSensor);
    LOGD("Initializing mono: sy ActivateMode %d",sy->mbActivateLocalizationMode);
    LOGD("Initializing mono: sy DeActivateMode %d",sy->mbDeactivateLocalizationMode);
    LOGD("Initializing mono: sy mbReset %d",sy->mbReset);

*/
    //LOGD("Initializing mono: addr of sy2 is %p", &sy2);
    //LOGD("Initializing mono: addr of sy1 is %p", sy);
    //LOGD("Initializing mono: the type of sys %s", typeid(*sy).name());
    //LOGD("Initializing mono: the size of sy1 %d", sizeof(sy2));
    //LOGD("Initializing mono: the size of sy2 %d", sizeof(*sy));
    //LOGD("Initializing mono: success creating the sys");
    const jlong slamaddr = 12345;// = &SLAM;
    return slamaddr;
}

/*
 * Class:     com_example_castoryan_orb_MyNDK
 * Method:    TrackMonocular
 * Signature: (JD)J
 */
JNIEXPORT jlong JNICALL Java_com_example_castoryan_orb_MyNDK_TrackMonocular
        (JNIEnv * env, jobject obj, jlong addr, jdouble time){
/*        const cv::Mat* im = addr;
        const double* timestamp = time;

        const cv::Mat* backim = TrackMonocular(im, timestamp);*/
        //const jlong backaddr = 123456789; //backim;
        //(jlong) ptr;

    /* LOGD("Tracking mono: The img col is %p",&im);
        LOGD("Tracking mono: The received addr is %p", (cv::Mat *)addr);

        LOGD("Tracking mono: addr of sy1 is %p", sy);
        LOGD("Tracking mono: the type of sys %s",typeid(*sy).name());
        LOGD("Tracking mono: the size of sys %d", sizeof(*sy));


        LOGD("Tracking mono: im is  %p", im);
        LOGD("Tracking mono: ttrack is  %f", ttrack);
        */
        return 0;
}


/*
 * Class:     com_example_castoryan_orb_MyNDK
 * Method:    Shutdown
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_example_castoryan_orb_MyNDK_Shutdown
        (JNIEnv *env, jobject obj,jlong addr){

    const cv::Mat *im = (cv::Mat*)addr;

    //LOGD("IN shutdown: thread id is %lu",std::this_thread::get_id());
    //LOGD("IN shutdown: mSensor is %d", sy->mSensor);
    //LOGD("IN shutdown: ActivateMode %d",sy->mbActivateLocalizationMode);
    //LOGD("IN shutdown: DeActivateMode %d",sy->mbDeactivateLocalizationMode);
    //LOGD("IN shutdown: mbReset %d",sy->mbReset);
    //LOGD("===============================");

    //LOGD("The received addr is %ld", (long)addr);
    //LOGD("The received addr is %p", (cv::Mat *)addr);
    //LOGD("The img addr &im is %p",&im);
    //LOGD("The img addr im is  %p",im);

}



