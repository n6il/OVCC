# change application name here (executable output name)
TARGET=testlib
 
# compiler
CC=gcc
# linker
LD=gcc
# Resource Compiler
# RC=windres
# debug
DEBUG=-g
# optimisation
OPT=-O0#2
# warnings
WARN=#-Wall
# Include Path 
INCDIR=# -I /usr/include/boost/predef/os
# Obj Dir
ODIR = obj

PTHREAD=#-pthread

SDLINC=`pkg-config --cflags sdl2`
AGARINC=`agar-config --cflags`
IDIR=$(INCDIR) $(SDLINC) $(AGARINC)
 
CCFLAGS=$(IDIR) $(DEBUG) $(OPT) $(WARN) -fPIC
 
SDLLIB=`sdl2-config --libs`
AGARLIB=`agar-config --libs`
LIBS=$(SDLLIB) $(AGARLIB)

LDFLAGS=-shared $(PTHREAD) $(LIBS) #-Wl,--out-implib,libharddisk.a # -export-dynamic 

UNUSEDOBJS= 

_OBJS=	orch90.o profport.o
OBJS= $(patsubst %,$(ODIR)/%,$(_OBJS))

testlib: obj/testlib.o liborch90.so
	$(LD) -o $@ $< $(LIBS)

$(ODIR)/testlib.o: testlib.c
	$(CC) -O0 -g -c $< -o $@

liborch90.so: $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) $(LIBS) -o $@ 
    
$(ODIR)/orch90.o: orch90.c orch90.h
	$(CC) -c $(CCFLAGS) $< -o $@

$(ODIR)/profport.o: ../CoCo/profport.c ../CoCo/profport.h
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -f $(ODIR)/*.o $(TARGET) liborch90.so

install:
	sudo cp liborch90.so /usr/lib
	sudo ldconfig
	cp liborch90.so ../CoCo
