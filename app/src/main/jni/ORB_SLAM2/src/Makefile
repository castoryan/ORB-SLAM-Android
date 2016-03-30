NDK = /home/castoryan/Android/standalone_toolchain
CC= $(NDK)/bin/arm-linux-androideabi-gcc-4.9 

#SYSROOT=$(NDK)/sysroot
CFLAGS = -march=armv7-a -mfloat-abi=softfp -mfpu=neon
LDFLAGS = -march=armv7-a-WI, --fix-cortex-a8
CF = $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -fPIC -O 
I = -I../Include
RANLIB = ranlib
ARCHIVE = $(AR) $(ARFLAGS)

all: libcsparse.so

CS = cs_add.o cs_amd.o cs_chol.o cs_cholsol.o cs_counts.o cs_cumsum.o \
	cs_droptol.o cs_dropzeros.o cs_dupl.o cs_entry.o \
	cs_etree.o cs_fkeep.o cs_gaxpy.o cs_happly.o cs_house.o cs_ipvec.o \
	cs_lsolve.o cs_ltsolve.o cs_lu.o cs_lusol.o cs_util.o cs_multiply.o \
	cs_permute.o cs_pinv.o cs_post.o cs_pvec.o cs_qr.o cs_qrsol.o \
	cs_scatter.o cs_schol.o cs_sqr.o cs_symperm.o cs_tdfs.o cs_malloc.o \
	cs_transpose.o cs_compress.o cs_usolve.o cs_utsolve.o cs_scc.o \
	cs_maxtrans.o cs_dmperm.o cs_updown.o cs_print.o cs_norm.o cs_load.o \
	cs_dfs.o cs_reach.o cs_spsolve.o cs_ereach.o cs_leaf.o cs_randperm.o

$(CS): ../Include/cs.h Makefile

%.o: ./%.cc ../Include/%.h
	$(CC) $(CF) $(I) -c $<

libcsparse.so: $(CS)
	$(CC) $(CF) -shared -o libcsparse.so $(CS)

clean:
	- $(RM) *.o

purge: distclean

distclean: clean
	- $(RM) *.a *.obj *.dll
