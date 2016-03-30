/** Project: ORB-SLAM-Android.
 *  For more information see <https://github.com/castoryan/ORB-SLAM-Android>
 *
 *  filename: MyNDK.java
 *
 *  Created by Qinrui Yan on 30/Oct/2016.
 *  E-mail: castoryan1991@gmail.com
 *
 *  Copyright © 2016 Qinrui Yan. All rights reserved.
 */



package com.example.castoryan.orb;


public class MyNDK{
    static {
            System.loadLibrary("mono");
    }
        public native String test(int a, int b);
        public native void System(String vocfile, String setfile, int a,  boolean b, long c, int d);
        public native long TrackMonocular(long im, double time);
        public native void Shutdown(long addr);

}