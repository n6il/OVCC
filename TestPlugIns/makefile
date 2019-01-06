# change application name here (executable output name)
TARGET=testlib
 
# compiler
CC=gcc
# linker
LD=gcc
# debug
DEBUG=-g
# optimisation
OPT=-O0
# warnings
WARN=#-Wall
# Include Path 
INCDIR=#-I../CoCo
# Obj Dir
ODIR = obj

PTHREAD=-pthread

SDLINC=`sdl2-config --cflags`
AGARINC=`agar-config --cflags`
IDIR=$(INCDIR) $(SDLINC) $(AGARINC)
 
CCFLAGS=$(IDIR) $(DEBUG) $(OPT) $(WARN) -fPIC
 
SDLLIB=`sdl2-config --libs`
AGARLIB=`agar-config --libs`
LIBS=$(AGARLIB) $(SDLLIB) 

LDFLAGS=-shared $(PTHREAD) -s -Wl,--out-implib,libplugin.a

UNUSEDOBJS= 

_OBJS=plugin.o
OBJS= $(patsubst %,$(ODIR)/%,$(_OBJS))

testlib: obj/testlib.o plugin.dll
	$(LD) -o $@ $< $(LIBS) -Wl,--subsystem,console

$(ODIR)/testlib.o: testlib.c
	$(CC) -O0 -g -c $(IDIR) $< -o $@

plugin.dll: $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) plugin.def $(LIBS) -o $@ 
    
$(ODIR)/plugin.o: plugin.c
	$(CC) -c $(CCFLAGS) $< -o $@

clean:
	rm -f $(ODIR)/*.o $(TARGET) plugin.dll libpluin.a
