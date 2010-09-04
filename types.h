#ifndef TYPES_H
#define TYPES_H

typedef unsigned char         u8;
typedef unsigned short int    u16;
typedef unsigned int          u32;
typedef unsigned long int     u64;


typedef struct {
   union {
      struct {
         u16 limit;
         u32 base;
      } __attribute__((packed)) s;
      u64 v;
   };
} gdtr_t;

#endif