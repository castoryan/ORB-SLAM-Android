/** Project: ORB-SLAM-Android.
 *  For more information see <https://github.com/castoryan/ORB-SLAM-Android>
 *
 *  filename: MainActivity.java
 *
 *  Created by Qinrui Yan on 30/Oct/2016.
 *  E-mail: castoryan1991@gmail.com
 *
 *  Copyright © 2016 Qinrui Yan. All rights reserved.
 */

package com.example.castoryan.orb;

import org.opencv.android.BaseLoaderCallback;
import org.opencv.android.CameraBridgeViewBase;
import org.opencv.android.CameraBridgeViewBase.CvCameraViewFrame;
import org.opencv.android.CameraBridgeViewBase.CvCameraViewListener2;
import org.opencv.android.LoaderCallbackInterface;
import org.opencv.android.OpenCVLoader;
import org.opencv.core.Core;
import org.opencv.core.Mat;
import org.opencv.core.Size;
import org.opencv.imgproc.Imgproc;

import android.app.Activity;
import android.os.Environment;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;

import android.view.MenuItem;
import android.view.SurfaceView;
import android.view.View;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.Toast;


import java.io.File;


public class MainActivity extends Activity implements CvCameraViewListener2  {
    private static final String TAG = "OCVSample::Activity";

    private CameraBridgeViewBase    mOpenCvCameraView;
    private boolean                 mIsJavaCamera = true;
    private MenuItem                mItemSwitchCamera = null;
    private MenuItem                mItemStartSLAM = null;
    private boolean                 mIsSLAMstart = false;
    private boolean                 mIsSLAMgoing = false;
    private boolean                 mIsSLAMshutdown = false;


    private BaseLoaderCallback mLoaderCallback = new BaseLoaderCallback(this) {
        @Override
        public void onManagerConnected(int status) {
            switch (status) {
                case LoaderCallbackInterface.SUCCESS:
                {
                    Log.i(TAG, "OpenCV loaded successfully");
                    mOpenCvCameraView.enableView();
                } break;
                default:
                {
                    super.onManagerConnected(status);
                } break;
            }
        }
    };

    public MainActivity() {
        Log.i(TAG, "Instantiated new " + this.getClass());
    }


    MyNDK mn;
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        Log.i(TAG, "called onCreate");
        super.onCreate(savedInstanceState);
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);

        setContentView(R.layout.activity_main);

        if (mIsJavaCamera)
            mOpenCvCameraView = (CameraBridgeViewBase) findViewById(R.id.tutorial1_activity_java_surface_view);
        else
            mOpenCvCameraView = (CameraBridgeViewBase) findViewById(R.id.tutorial1_activity_native_surface_view);

        mOpenCvCameraView.setVisibility(SurfaceView.VISIBLE);

        mOpenCvCameraView.setCvCameraViewListener(this);
        mn = new MyNDK();

        Button bt = (Button)findViewById(R.id.bt1);
        bt.setOnClickListener(new View.OnClickListener() {
            String toastMesage = new String();

            public void onClick(View v) {
                // Perform action on click
                mIsSLAMstart = true;
                toastMesage = "Initializing the SLAM system";
                Toast toast = Toast.makeText(getApplicationContext(), toastMesage, Toast.LENGTH_LONG);
                toast.show();
            }
        });


        Button bt2 = (Button)findViewById(R.id.bt2);
        bt2.setOnClickListener(new View.OnClickListener() {
            String toastMesage =  new String();
            public void onClick(View v) {
                // Perform action on click

                mIsSLAMshutdown = true;

                toastMesage = "Shut down the SLAM system";
                Toast toast = Toast.makeText(getApplicationContext(), toastMesage, Toast.LENGTH_LONG);
                toast.show();
            }
        });


    }

    @Override
    public void onPause()
    {
        super.onPause();
        if (mOpenCvCameraView != null)
            mOpenCvCameraView.disableView();
    }

    @Override
    public void onResume() {
        super.onResume();
        OpenCVLoader.initAsync(OpenCVLoader.OPENCV_VERSION_2_4_3, this, mLoaderCallback);
    }

    public void onDestroy() {
        super.onDestroy();
        if (mOpenCvCameraView != null)
            mOpenCvCameraView.disableView();
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        Log.i(TAG, "called onCreateOptionsMenu");
        mItemSwitchCamera = menu.add("Toggle Native/Java camera");
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        String toastMesage = new String();
        Log.i(TAG, "called onOptionsItemSelected; selected item: " + item);

        if (item == mItemSwitchCamera) {
            mOpenCvCameraView.setVisibility(SurfaceView.GONE);
            mIsJavaCamera = !mIsJavaCamera;

            if (mIsJavaCamera) {
                mOpenCvCameraView = (CameraBridgeViewBase) findViewById(R.id.tutorial1_activity_java_surface_view);
                toastMesage = "Java Camera";
            } else {
                mOpenCvCameraView = (CameraBridgeViewBase) findViewById(R.id.tutorial1_activity_native_surface_view);
                toastMesage = "Native Camera";
            }

            mOpenCvCameraView.setVisibility(SurfaceView.VISIBLE);
            mOpenCvCameraView.setCvCameraViewListener(this);
            mOpenCvCameraView.enableView();
            Toast toast = Toast.makeText(this, toastMesage, Toast.LENGTH_LONG);
            toast.show();
        }

        if (item == mItemStartSLAM) {
            //mIsSLAMstart = !mIsSLAMstart;
            if(!mIsSLAMstart){

            }
            mn.Shutdown(123);
            toastMesage = "SLAM is "+mIsSLAMstart;
            Toast toast = Toast.makeText(this, toastMesage, Toast.LENGTH_LONG);
            toast.show();

        }

        return true;
    }

    public void onCameraViewStarted(int width, int height) {
    }

    public void onCameraViewStopped() {
    }



    // Image processing here!!
    public Mat onCameraFrame(CvCameraViewFrame inputFrame) {

        try{
            //Thread.currentThread().sleep(50);
        }
        catch(Exception e){}


        if(mIsSLAMshutdown == true){
            mn.System("", "", 0, true, 0, 3);
            mIsSLAMshutdown = false;
        }



        Mat im = inputFrame.rgba();
        Imgproc.resize(im, im, new Size(640.0, 480.0));
        long add = im.getNativeObjAddr();


        if(mIsSLAMgoing == true){
            mn.System("", "", 0, true, add, 2);
        }



        if(mIsSLAMstart){
            final String mExternalDirectory = Environment.getExternalStorageDirectory().getAbsolutePath();

            String campar = mExternalDirectory + "/ORB2/";
            Log.d("orb_debug", "Path: " + campar);
            File f = new File(campar);
            final File file[]=f.listFiles();
            Log.d("orb_debug", "Size: " + file.length);
            for (int i = 0; i < file.length; i++) {
                Log.d("orb_debug", "FileName:" + file[i].getName());
            }

            if (file.length == 2) {
                mn.System(mExternalDirectory + "/ORB2/" + file[1].getName(), mExternalDirectory + "/ORB2/" + file[0].getName(), 0, true, 0, 1);
            }
            mIsSLAMstart = false;
            mIsSLAMgoing = true;
        }

        return inputFrame.rgba();
    }

}


