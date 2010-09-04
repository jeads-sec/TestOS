#include "print.h"

static unsigned char *videoram = (unsigned char *) 0xb8000;
static int xpos = 0, ypos = 0;

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