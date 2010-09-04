#ifndef REGS_H
#define REGS_H

#include "types.h"

u32 read_cr0(void);

void write_cr0(u32 new_cr0);

u32 read_cr4(void);

void write_cr4(u32 new_cr4);

void read_gdtr(u64* gdtr);

#endif