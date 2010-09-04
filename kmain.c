#include "print.h"

/* [character][mode] [character][mode] ... */
/* 80 wide, 25 high */
unsigned char *videoram = (unsigned char *) 0xb8000;
int xpos = 0, ypos = 0;

inline void
add_newline()
{
   xpos = 0;
   ypos++;
}

inline void 
put_char(char c)
{
   videoram[ypos*80+xpos] = c;
   videoram[ypos*80+xpos+1] = 0x07;
   xpos += 2;
   if(xpos > 80) {
      add_newline();
   }
}

void 
print(char* string)//, int len)
{
   int cur_char = 0;
   while(string[cur_char] != 0) {
      //put_char(string[cur_char], videoram);
      //videoram += 2;
      if(string[cur_char] == '\n') {
         add_newline();
         cur_char++;
         continue;
      }
      put_char(string[cur_char]);
      cur_char++;
   }
   
}

void 
print_hex(int input)
{
   short shift = 28;
   while(shift >= 0) {
      put_char(((input & (0xF << shift)) >> shift) + 48);
      shift -= 4;
   }   
   add_newline();
}

void clear_screen()
{
   xpos = 0;
   ypos = 0;
   while(ypos < 25) {
      put_char(' ');
   }
   xpos = 0;
   ypos = 0;
}

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
   //print_hex(0x12345678);
   //print(boot_loader_name, 16);
 
   /* Write your kernel here. */
}