#include "console.h"
#include "multiboot.h"
#include "init.h"

int kinit(uint32_t magic, struct mbootinfo* mbtinfo){
    clscr();
    print("BingoKernel Starting...");
    puts("magic:");
    shownum(magic);
    conenter();
    puts("memlower:");
    shownum(mbtinfo->mem_lower);
    conenter();
    puts("memupper:");
    shownum(mbtinfo->mem_upper);
    return 0;
}