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
OPT=-O0
# warnings
WARN=#-Wall
# Include Path 
INCDIR=# -I /usr/include/boost/predef/os
# Obj Dir
ODIR = obj

PTHREAD=#-pthread

SDLINC=#`pkg-config --cflags sdl2`
AGARINC=`agar-config --cflags`
IDIR=$(INCDIR) $(SDLINC) $(AGARINC)
 
CCFLAGS=$(IDIR) $(DEBUG) $(OPT) $(WARN) -fPIC
 
SDLLIB=#`sdl2-config --libs`
AGARLIB=#`agar-config --libs`
POSSIBLE_LIBS= -lm -lWinmm -lgdi32 -ldxguid -lddraw -ldsound -ldinput -ldinput8 -lComctl32 -lole32
LIBS=$(SDLLIB) $(AGARLIB)

LDFLAGS=-shared $(PTHREAD) $(LIBS) #-Wl,--out-implib,libharddisk.a # -export-dynamic 

UNUSEDOBJS= 

_OBJS=	mpi.o fileops.o
OBJS= $(patsubst %,$(ODIR)/%,$(_OBJS))

testlib: obj/testlib.o libmpi.so
	$(LD) -o $@ $< -lprofport -ldl `sdl2-config --libs` `agar-config --libs`

$(ODIR)/testlib.o: testlib.c
	$(CC) -O0 -g -c -I /usr/local/include/agar $< -o $@

libmpi.so: $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -lprofport `sdl2-config --libs` `agar-config --libs` -o $@ 
    
$(ODIR)/mpi.o: mpi.c mpi.h ../CoCo/fileops.h
	$(CC) -c $(CCFLAGS) $< -o $@

$(ODIR)/fileops.o: ../CoCo/fileops.c ../CoCo/fileops.h
	$(CC) -c $(CCFLAGS) $< -o $@
    
clean:
	rm -f $(ODIR)/*.o $(TARGET) libmpi.so

install:
	sudo cp libmpi.so /usr/lib
	sudo ldconfig
	cp libmpi.so ../CoCo
