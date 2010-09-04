#!/bin/bash

nasm -f elf -o loader.o loader.s
x86_64-elf-gcc -o kmain.o -c kmain.c -m32 -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs
x86_64-elf-ld -melf_i386 -T linker.ld -o kernel.bin loader.o kmain.o

cp kernel.bin /Volumes/GRUB/boot/