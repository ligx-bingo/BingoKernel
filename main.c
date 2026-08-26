#include "main.h"
#include "console.h"
#include "multiboot.h"
#include "init.h"

int main(uint32_t magic, struct mbootinfo* mbtinfo){
    kinit(magic,mbtinfo);
    while(1);
}