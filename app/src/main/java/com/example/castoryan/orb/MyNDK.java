package com.example.castoryan.orb;

/**
 * Created by castoryan on 21.03.16.
 */
public class MyNDK{
    static {
/*        System.loadLibrary("g2o_ext_csparse");
        System.loadLibrary("g2o_cli");
        System.loadLibrary("g2o_core");
        System.loadLibrary("g2o_csparse_extension");
        System.loadLibrary("g2o_hierarchical");
        System.loadLibrary("g2o_interface");
        System.loadLibrary("g2o_parser");

        System.loadLibrary("g2o_solver_csparse");
        System.loadLibrary("g2o_solver_dense");
        System.loadLibrary("g2o_solver_eigen");
        System.loadLibrary("g2o_solver_pcg");
        System.loadLibrary("g2o_solver_slam2d_linear");
        System.loadLibrary("g2o_solver_structure_only");

        System.loadLibrary("g2o_stuff");
        System.loadLibrary("g2o_tutorial_slam2d");

        System.loadLibrary("g2o_types_icp");
        System.loadLibrary("g2o_types_sba");
        System.loadLibrary("g2o_types_sim3");
        System.loadLibrary("g2o_types_slam2d");
        System.loadLibrary("g2o_types_slam2d_addons");*/
        //if (!OpenCVLoader.initDebug()){

        //}
        //else {
            System.loadLibrary("mono");
        //}
    }

        public native String test(int a, int b);
        public native void System(String vocfile, String setfile, int a,  boolean b, long c, int d);
        public native long TrackMonocular(long im, double time);
        public native void Shutdown(long addr);

}