#!/bin/bash -xe
cd CoCo
mkdir -p obj
make -f Makefiles/Linux/makefile clean
make -f Makefiles/Linux/makefile ovcc
cd ..
cd FD502
mkdir -p obj
make -f Makefiles/Linux/makefile clean
make -f Makefiles/Linux/makefile libfd502.so
cp libfd502.so ../CoCo
cd ..
cd HardDisk
mkdir -p obj
make -f Makefiles/Linux/makefile clean
make -f Makefiles/Linux/makefile libharddisk.so
cp libharddisk.so ../CoCo
cd ..
cd Ramdisk
mkdir -p obj
make -f Makefiles/Linux/makefile clean
make -f Makefiles/Linux/makefile libramdisk.so
cp libramdisk.so ../CoCo
cd ..
cd SuperIDE
mkdir -p obj
make -f Makefiles/Linux/makefile clean
make -f Makefiles/Linux/makefile libsuperide.so
cp libsuperide.so ../CoCo
cd ..
#cd TestPlugIns
#make -f Makefiles/Linux/makefile
#cd ..
cd becker
mkdir -p obj
make -f Makefiles/Linux/makefile clean
make -f Makefiles/Linux/makefile libbecker.so
cp libbecker.so ../CoCo
cd ..
cd mpi
mkdir -p obj
make -f Makefiles/Linux/makefile clean
make -f Makefiles/Linux/makefile libmpi.so
cp libmpi.so ../CoCo
cd ..
cd orch90
mkdir -p obj
make -f makefiles/Linux/makefile clean
make -f makefiles/Linux/makefile liborch90.so
cp liborch90.so ../CoCo
cd ..
