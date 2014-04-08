# configure for nnforge
AC_INIT(nnforge,1.1.3)
AC_CONFIG_SRCDIR(Makefile.am)
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE
AM_CONFIG_HEADER(config.h)

ac_default_prefix=`pwd`
bindir=$ac_default_prefix/bin/$host
libdir=$ac_default_prefix/lib/$host
AC_PROG_INSTALL
AC_CANONICAL_HOST

AC_PROG_CC(gcc cc)
AC_PROG_CXX(c++ g++ egcs gcc)
AC_PROG_LIBTOOL

AC_LANG_PUSH([C++])

BOOST_REQUIRE
BOOST_THREADS([mt])
BOOST_REGEX([mt])
BOOST_CHRONO([mt])
BOOST_FILESYSTEM([mt])
BOOST_PROGRAM_OPTIONS([mt])
#BOOST_RANDOM([mt])
BOOST_SYSTEM([mt])
BOOST_DATE_TIME([mt])

#- cuda
AC_ARG_ENABLE(cuda,
AC_HELP_STRING([--enable-cuda],[Enable CUDA support (default is NO)]),
[case "${enableval}" in
        yes) cuda=true ;;
	no) cuda=false ;;
	*) AC_MSG_ERROR(bad_value ${enableval} for --enable-cuda) ;;
esac],[cuda=false])
AM_CONDITIONAL(ENABLE_CUDA_BACKEND, test x$cuda = xtrue)
if test x$cuda = xtrue; then
   AC_DEFINE(HAVE_CUDA,1,"CUDA backend")
fi

AC_ARG_ENABLE(cudaprofiling,
AC_HELP_STRING([--enable-cuda-profiling],[Enable CUDA profiling support (default is NO)]),
[case "${enableval}" in
        yes) cudaprofiling=true ;;
	no) cudaprofiling=false ;;
	*) AC_MSG_ERROR(bad_value ${enableval} for --enable-cuda-profiling) ;;
esac],[cudaprofiling=false])
AM_CONDITIONAL(ENABLE_CUDA_PROFILING, test x$cuda = xtrue)
if test x$cudaprofiling = xtrue; then
   AC_DEFINE(HAVE_CUDA_PROFILING,1,"CUDA profiling")
fi

# Requires OpenCV >= 2.0
# XXX: configure / pkg-config madness: if the PKG_CHECK_MODULES
# is put within the if / else conditional, no other pkg-config
# libraries are detected.
PKG_CHECK_MODULES([opencv],[opencv >= 2.0],opencv2=true,opencv2=false)
AC_ARG_ENABLE(opencv,
AC_HELP_STRING([--disable-opencv],[Don't use opencv (activates image similarity analysis) (default is NO)]),
[enableval2=$enableval],
[enableval2=yes])
if test $enableval2 = yes; then
#   PKG_CHECK_MODULES([opencv],[opencv >= 2.0],opencv2=true,opencv2=false)
   if test x$opencv2 = xtrue; then
       AC_DEFINE(FEATURE_OPENCV2,1,"OpenCV library is there")
   fi
   AM_CONDITIONAL(HAVE_OPENCV2,test x$opencv2 = xtrue)
else
   AC_SUBST(opencv2,false)
   AM_CONDITIONAL(HAVE_OPENCV2,false)
fi		     

AC_OUTPUT(Makefile nnforge/Makefile examples/Makefile)
