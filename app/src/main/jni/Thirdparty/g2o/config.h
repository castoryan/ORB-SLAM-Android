#ifndef G2O_CONFIG_H
#define G2O_CONFIG_H


/* #undef G2O_HAVE_OPENGL */
/* #undef G2O_OPENGL_FOUND */
/* #undef G2O_OPENMP */
#define G2O_SHARED_LIBS 1
#define G2O_LGPL_SHARED_LIBS 1

// available sparse matrix libraries
/* #undef G2O_HAVE_CHOLMOD */
#define G2O_HAVE_CSPARSE 1

#define G2O_CXX_COMPILER "GNU /home/castoryan/Android/Sdk/ndk-bundle/toolchains/arm-linux-androideabi-4.9/prebuilt/linux-x86_64/bin/arm-linux-androideabi-g++"

#ifdef __cplusplus
#include <g2o/core/eigen_types.h>
#endif

#endif
