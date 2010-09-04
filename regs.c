#include "regs.h"
#include "types.h"

u32
read_cr0()
{
   u32 cr0 = 0;
   asm(
      "mov %%cr0, %0"
      :"=r"(cr0)
      );
   return cr0;
}

void
write_cr0(u32 new_cr0)
{
   asm(
      "mov %0, %%cr0"
      :
      : "r" (new_cr0)
      );
   return;
}

u32
read_cr4()
{
   u32 cr4 = 0;
   asm(
      "mov %%cr4, %0"
      :"=r"(cr4)
      );
   return cr4;
}

void 
write_cr4(u32 new_cr4)
{
   asm(
      "mov %0, %%cr4"
      :
      : "r" (new_cr4)
      );
   return;
}

/* GDT */
void
read_gdtr(u64* gdtr)
{
   asm volatile(
      "sgdt %0"
      : "=m" (gdtr)
      );
   return;
}