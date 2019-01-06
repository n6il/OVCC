#ifndef __TCC1014MMU_H__
#define __TCC1014MMU_H__

/*
Copyright 2015 by Joseph Forgione
This file is part of VCC (Virtual Color Computer).

    VCC (Virtual Color Computer) is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    VCC (Virtual Color Computer) is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with VCC (Virtual Color Computer).  If not, see <http://www.gnu.org/licenses/>.
*/


#ifdef __cplusplus
extern "C" void MemWrite8(unsigned char,unsigned short );
extern "C" unsigned char MemRead8(short unsigned int);
#else
extern void MemWrite8(unsigned char,unsigned short );
extern unsigned char MemRead8(short unsigned int);
#endif
void MemWrite16(unsigned short,unsigned short );

unsigned short MemRead16(short unsigned int);
unsigned char * MmuInit(unsigned char);
unsigned char *	Getint_rom_pointer(void);
unsigned char * Getext_rom_pointer(void);

void fMemWrite8(unsigned char,unsigned short );
unsigned char fMemRead8(short unsigned int);

int load_int_rom(char * );
void SetMapType(unsigned char);
void CopyRom(void);
void Set_MmuTask(unsigned char);
void SetMmuRegister(unsigned char,unsigned char);
void Set_MmuEnabled (unsigned char );
void SetRomMap(unsigned char );
void SetVectors(unsigned char);
void MmuReset(void);
void SetDistoRamBank(unsigned char);
void SetMmuPrefix(unsigned char);
void SetCartMMU (unsigned char);

#define _128K	0	
#define _512K	1
#define _2M		2

#endif
