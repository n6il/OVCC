#!/bin/bash -xe
cd CoCo
make -f Makefiles/Linux/makefile clean
cd ..
cd FD502
make -f Makefiles/Linux/makefile clean
cd ..
cd HardDisk
make -f Makefiles/Linux/makefile clean
cd ..
cd Ramdisk
make -f Makefiles/Linux/makefile clean
cd ..
cd SuperIDE
make -f Makefiles/Linux/makefile clean
cd ..
#cd TestPlugIns
#make -f Makefiles/Linux/makefile
#cd ..
cd becker
make -f Makefiles/Linux/makefile clean
cd ..
cd mpi
make -f Makefiles/Linux/makefile clean
cd ..
cd orch90
make -f Makefiles/Linux/makefile clean
cd ..
