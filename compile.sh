mips64-gcc -c -I /opt/n64-dev/n64-sysroot/include hello_world.c -o hello_world.o
mips64-g++ -T /opt/n64-dev/n64-sysroot/lib/gl-n64.ld -nostdlib -Wl,--defsym,start=0x80400000 hello_world.o -o hello_world.elf
mips64-objcopy hello_world.elf hello_world.bin -O binary
#luapatch patch-data.lua -text hook.gsc -bin 80400000 mario.elf.bin
