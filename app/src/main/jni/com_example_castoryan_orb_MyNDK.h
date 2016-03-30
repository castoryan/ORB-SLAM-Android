/** Project: ORB-SLAM-Android.
 *  For more information see <https://github.com/castoryan/ORB-SLAM-Android>
 *
 *  The original work was done by Raúl Mur-Artal <raulmur at unizar dot es> (University of Zaragoza)
 *  For more information see <https://github.com/raulmur/ORB_SLAM2>
 *
 *  filename: com_example_castoryan_orb_MyNDK.h
 *
 *  Created or Edited by Qinrui Yan on 30/Oct/2016.
 *  E-mail: castoryan1991@gmail.com
 *  Copyright © 2016 Qinrui Yan. All rights reserved.
 */


#include <jni.h>
/* Header for class com_example_castoryan_orb_MyNDK */

#ifndef _Included_com_example_castoryan_orb_MyNDK
#define _Included_com_example_castoryan_orb_MyNDK
#ifdef __cplusplus
extern "C" {
#endif

std::thread* th1;
std::thread* th2;
std::thread* th3;

std::mutex mt1;

/*
 * Class:     com_example_castoryan_orb_MyNDK
 * Method:    test
 * Signature: (II)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_example_castoryan_orb_MyNDK_test
  (JNIEnv *, jobject, jint, jint);

/*
 * Class:     com_example_castoryan_orb_MyNDK
 * Method:    System
 * Signature: (Ljava/lang/String;Ljava/lang/String;IZ)V
 */
JNIEXPORT jlong JNICALL Java_com_example_castoryan_orb_MyNDK_System
  (JNIEnv *, jobject, jstring, jstring, jint, jboolean, jlong, jint);

/*
 * Class:     com_example_castoryan_orb_MyNDK
 * Method:    TrackMonocular
 * Signature: (JD)J
 */
JNIEXPORT jlong JNICALL Java_com_example_castoryan_orb_MyNDK_TrackMonocular
  (JNIEnv *, jobject, jlong, jdouble);

/*
 * Class:     com_example_castoryan_orb_MyNDK
 * Method:    Shutdown
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_example_castoryan_orb_MyNDK_Shutdown
  (JNIEnv *, jobject, jlong);

#ifdef __cplusplus
}
#endif
#endif
