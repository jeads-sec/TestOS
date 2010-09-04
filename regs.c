#include "regs.h"

int
read_cr0()
{
   int cr0 = 0;
   asm(
      "mov %%cr0, %0"
      :"=r"(cr0)
      );
   return cr0;
}

void
write_cr0(int new_cr3)
{
   asm(
      "mov %0, %%cr0"
      :
      : "r" (new_cr3)
      );
   return;
}

int
read_cr4()
{
   int cr4 = 0;
   asm(
      "mov %%cr4, %0"
      :"=r"(cr4)
      );
   return cr4;
}