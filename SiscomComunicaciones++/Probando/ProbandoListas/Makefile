#############################################################################
# Makefile for building: Probando
# Generated by qmake (1.07a) (Qt 3.3.8b) on: Mon Dec 30 08:04:46 2019
# Project:  ProbandoListas.pro
# Template: app
# Command: $(QMAKE) -o Makefile ProbandoListas.pro
#############################################################################

####### Compiler, tools and options

CC       = gcc
CXX      = g++
LEX      = flex
YACC     = yacc
CFLAGS   = -pipe -Wall -W -g  -DQT_SHARED -DQT_NO_DEBUG -DQT_THREAD_SUPPORT
CXXFLAGS = -pipe -Wall -W -g  -DQT_SHARED -DQT_NO_DEBUG -DQT_THREAD_SUPPORT
LEXFLAGS = 
YACCFLAGS= -d
INCPATH  = -I/home/hgarduno/SiscomDesarrollo/Qt/3.3.8-CXX-9.2.0.64.Bits/mkspecs/default -I. -IH -I../../H -I$(QTDIR)/include
LINK     = g++
LFLAGS   =  -Wl,-rpath,$(QTDIR)/lib
LIBS     = $(SUBLIBS) -L$(QTDIR)/lib -L/usr/X11R6/lib -L../../ -L../../../SiscomDesarrollo4++ -lSiscomComunicaciones++ -lSiscomDesarrollo4++ -lqt-mt -lXext -lX11 -lm
AR       = ar cqs
RANLIB   = 
MOC      = $(QTDIR)/bin/moc
UIC      = $(QTDIR)/bin/uic
QMAKE    = qmake
TAR      = tar -cf
GZIP     = gzip -9f
COPY     = cp -f
COPY_FILE= $(COPY)
COPY_DIR = $(COPY) -r
INSTALL_FILE= $(COPY_FILE)
INSTALL_DIR = $(COPY_DIR)
DEL_FILE = rm -f
SYMLINK  = ln -sf
DEL_DIR  = rmdir
MOVE     = mv -f
CHK_DIR_EXISTS= test -d
MKDIR    = mkdir -p

####### Output directory

OBJECTS_DIR = O/

####### Files

HEADERS = 
SOURCES = CPP/Probando.cpp \
		CPP/zDatosPersonales.cpp
OBJECTS = O/Probando.o \
		O/zDatosPersonales.o
FORMS = 
UICDECLS = 
UICIMPLS = 
SRCMOC   = 
OBJMOC = 
DIST	   = ProbandoListas.pro
QMAKE_TARGET = Probando
DESTDIR  = 
TARGET   = Probando

first: all
####### Implicit rules

.SUFFIXES: .c .o .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o $@ $<

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(UICDECLS) $(OBJECTS) $(OBJMOC)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJMOC) $(OBJCOMP) $(LIBS)

mocables: $(SRCMOC)
uicables: $(UICDECLS) $(UICIMPLS)

$(MOC): 
	( cd $(QTDIR)/src/moc && $(MAKE) )

Makefile: ProbandoListas.pro  /home/hgarduno/SiscomDesarrollo/Qt/3.3.8-CXX-9.2.0.64.Bits/mkspecs/default/qmake.conf ../../../../Qt/3.3.8-CXX-9.2.0.64.Bits/lib/libqt-mt.prl
	$(QMAKE) -o Makefile ProbandoListas.pro
qmake: 
	@$(QMAKE) -o Makefile ProbandoListas.pro

dist: 
	@mkdir -p O/Probando && $(COPY_FILE) --parents $(SOURCES) $(HEADERS) $(FORMS) $(DIST) O/Probando/ && ( cd `dirname O/Probando` && $(TAR) Probando.tar Probando && $(GZIP) Probando.tar ) && $(MOVE) `dirname O/Probando`/Probando.tar.gz . && $(DEL_FILE) -r O/Probando

mocclean:

uiclean:

yaccclean:
lexclean:
clean:
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) $(TARGET)


FORCE:

####### Compile

O/Probando.o: CPP/Probando.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o O/Probando.o CPP/Probando.cpp

O/zDatosPersonales.o: CPP/zDatosPersonales.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o O/zDatosPersonales.o CPP/zDatosPersonales.cpp

####### Install

install:  

uninstall:  

