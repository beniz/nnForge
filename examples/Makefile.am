bin_PROGRAMS=galaxy_z
galaxy_z_SOURCES=galaxy_zoo/galaxy_zoo.cpp galaxy_zoo/galaxy_zoo_testing_complete_result_set_visualizer.cpp  galaxy_zoo/galaxy_zoo_toolset.cpp

AM_CPPFLAGS=$(BOOST_CPPFLAGS) `pkg-config opencv --cflags`
AM_LDFLAGS=-lnnforge -lnnforge_plain $(BOOST_THREADS_LDFLAGS) $(BOOST_REGEX_LDFLAGS) $(BOOST_FILESYSTEM_LDFLAGS) $(BOOST_PROGRAM_OPTIONS_LDFLAGS) $(BOOST_CHRONO_LDFLAGS) $(BOOST_SYSTEM_LDFLAGS) $(BOOST_DATE_TIME_LDFLAGS) $(BOOST_SYSTEM_LDFLAGS) `pkg-config opencv --libs`
LDADD=-L/usr/lib -L../nnforge/ $(BOOST_THREADS_LIBS) $(BOOST_REGEX_LIBS) $(BOOST_FILESYSTEM_LIBS) $(BOOST_PROGRAM_OPTIONS_LIBS) $(BOOST_CHRONO_LIBS) $(BOOST_SYSTEM_LIBS) $(BOOST_DATE_TIME_LIBS) $(BOOST_SYSTEM_LIBS) 
