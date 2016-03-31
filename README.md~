
## ORB-SLAM-Android ##
----------


This project is based on the source code from Raul Mur-Artal.//
For more information or lastest updated of the source code, please go to: 
https://github.com/raulmur/ORB_SLAM2

The Native codes needed to be cross-compiled by android ndk. My test was based on android-ndk-r11.
http://developer.android.com/ndk/downloads/index.html

This project needs support of Opencv4Android 2.4.11, for more information, please go to: 
http://docs.opencv.org/2.4/doc/tutorials/introduction/android_binary_package/O4A_SDK.html

Other dependencies such as g2o, DBoW2, Eigen, were included in the project codes. 


----------


**To Build the code:**<br/>
1. excute *ndk-build* either Android Studio or in the terminal(if you have added ndk-build into the environment) in <br/> 
2. click "Run" in Android Studio <br/>


----------
**To Run the code:**<br/>
1. Place the vocabulary file and camera setting file into your /externalStorage/ORB2 folder, you should create this folder at the very first time.<br/>
please note: the external storage directory is getting by *getExternalStorageDirectory()*, the return values of this function varies for different brands of smartphones, so before starting the application, please double check if the file location is correct, and if the files are successfully loaded. Loading this two files unsuccessfully will make the app crash.<br/>

if you don't have this two files in hand, please download in:<br/>
1. vocabulary file <br/>
https://github.com/raulmur/ORB_SLAM2/tree/master/Vocabulary <br/>
2. setting file <br/>
https://github.com/raulmur/ORB_SLAM2/blob/master/Examples/Monocular/KITTI00-02.yaml <br/>

the parameters in the setting file should be reset according to your camera on the smartphone.<br/>

----------

**Something else**

Due to the compliexity and efficiency of the code, Viewer thread depends on pangolin library in the original work was disabled here.

By now, only basic functions were supported. The pose of every frame returns via android log files, which are easy to check via Android Studio. Some basic debug info have been added, feel free to add others as you need.

These codes were successfully test on Sony Xperia Z. It should be easily expanded to another platform.
Note that currently compiling only works for armeabi-v7a, please check the Application.mk and Android.mk files to fit your basic setting to the specific platform.

