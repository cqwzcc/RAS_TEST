AUTOMAKE_OPTIONS = foreign
INCLUDES = -I$(top_srcdir)/include -I/usr/include/libxml2

bin_PROGRAMS = $(top_srcdir)/bin/testRequestSlave
__top_srcdir__bin_testRequestSlave_SOURCES = main.cpp									 
__top_srcdir__bin_testRequestSlave_LDADD = $(top_builddir)/src/TEST/libtest.la \
										   $(top_srcdir)/lib/libcommon.la \
										   $(top_srcdir)/lib/libprotocol.la

noinst_LTLIBRARIES = $(top_builddir)/src/TEST/libtest.la
__top_builddir__src_TEST_libtest_la_SOURCES = \
										  ServerAgent.h \
										  ServerAgent.cpp \
										  ConfigManager.h \
										  ConfigManager.cpp \
										  ClientAgent.h \
										  ClientAgent.cpp \
										  HeartBeatTimer.h \
										  HeartBeatTimer.cpp

__top_builddir__src_TEST_libtest_la_LIBADD = \
									$(top_srcdir)/lib/libcommon.la \
			                     	$(top_srcdir)/lib/libprotocol.la

LIBS += -lprotobuf -lxml2
			                     	
