NDK_TOOLCHAIN_VERSION := 4.9
APP_MODULES := mono
APP_ABI := armeabi-v7a
APP_PLATFORM := android-18


#APP_STL:= gnustl_static
APP_STL:= gnustl_shared
APP_CPPFLAGS += -frtti
APP_CPPFLAGS += -fexceptions
APP_CPPFLAGS += -std=gnu++11
#LOCAL_C_INCLUDES += /home/castoryan/Android/android-ndk-r10e/sources/cxx-stl/gnu-libstdc++/4.9/include


#APP_CPPFLAGS := -std=c++11
#APP_STL := c++_shared
#APP_STL:= c++_static

LOCAL_C_INCLUDES += /home/castoryan/Android/android-ndk-r10e/sources/cxx-stl/llvm-libc++/libcxx/include
LIBCXX_FORCE_REBUILD := true