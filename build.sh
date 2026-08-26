nasm head.asm -o build/obj/head.o -f elf32

for src in *.c; do
    i686-elf-gcc -c "$src" \
                -o "build/obj/${src%.c}.o" \
                -ffreestanding -O2 -Wall -Wextra
done

i686-elf-gcc -T linker.ld \
            -o build/BingoKernel.elf \
            -ffreestanding -O2 -nostdlib \
            build/obj/*.o -lgcc