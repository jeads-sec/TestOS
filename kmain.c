#include "print.h"
#include "regs.h"
#include "types.h"

void kmain( void* mbd, unsigned int magic )
{
   if ( magic != 0x2BADB002 )
   {
      /* Something went not according to specs. Print an error */
      /* message and halt, but do *not* rely on the multiboot */
      /* data structure. */
   }
 
   /* You could either use multiboot.h */
   /* (http://www.gnu.org/software/grub/manual/multiboot/multiboot.html#multiboot_002eh) */
   /* or do your offsets yourself. The following is merely an example. */ 
   char * boot_loader_name =(char*) ((long*)mbd)[16];
   char* hello_str = "Hello, World!\n";
   
   clear_screen();
   print("CR0: ");
   print_hex(read_cr0());
   print("\n");
   print("CR4: ");
   print_hex(read_cr4());
   print("\n");
   
   print("GDTR Base: ");
   gdtr_t gdtr;
   read_gdtr(&gdtr.v);
   print_hex(gdtr.s.base);
   print("\n");
   print("GDTR Limit: ");
   print_hex(gdtr.s.limit);
   
   //print_hex(0x12345678);
   //print(boot_loader_name, 16);
 
   /* Write your kernel here. */
}