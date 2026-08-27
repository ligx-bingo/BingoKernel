#include "console.h"
#include "multiboot.h"
#include "init.h"

int kinit(uint32_t magic, struct mbootinfo* mbtinfo){
    clscr();
    print("BingoKernel Starting...");
    puts("magic:");
    shownum16(magic);
    conenter();
    puts("memlower:");
    shownum(mbtinfo->mem_lower);
    conenter();
    puts("memupper:");
    shownum(mbtinfo->mem_upper);
    conenter();
    puts("mmapaddr:");
    shownum16((int)mbtinfo->mmap_addr);
    conenter();
    printmmap(mbtinfo);
    return 0;
}

int printmmap(struct mbootinfo* mbtinfo){
    uint8_t* ptr = (uint8_t*)mbtinfo->mmap_addr;
    uint8_t* end = ptr + mbtinfo->mmap_length;

    while (ptr < end) {
        struct multiboot_mmap_entry* entry = (struct multiboot_mmap_entry*)ptr;
        uint64_t addr = ((uint64_t)entry->addr_high << 32) | entry->addr_low;
        uint64_t length = ((uint64_t)entry->len_high << 32) | entry->len_low;
        puts("addr: ");
        shownum16(addr); 
        putchar(' ');
        puts("len: ");
        shownum16(length);
        putchar(' ');
        puts("type: ");
        shownum16(entry->type);
        conenter();
        ptr += entry->size + 4;
    }
    return 0;
}