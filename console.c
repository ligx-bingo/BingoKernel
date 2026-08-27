#include "console.h"
int terx = 1;
int tery = 1;
char * videobuffer = (char*) VIDEOBUFFER;

int clscr(){
    for(int i=0;i < 4000;i++) videobuffer[i] = 0;
    terx = tery = 1;
    return 0;
}

int putchar(char c){
    videobuffer[((terx-1)*80 + tery-1)*2] = c;
    videobuffer[((terx-1)*80 + tery-1)*2+1] = 7;
    if(tery < 80){
        tery++;
    }
    else{
        conenter();
    }
    return 0;
}

int puts(char* str){
    int c = 0;
    while(str[c] != '\0'){
        putchar(str[c]);
        c++;
    }
    return 0;
}

int print(char* str){
    puts(str);
    conenter();
    return 0;
}

int conenter(){
    if(terx < 25){
        terx++;
        tery = 1;
    }
    else{
        for(int i = 0;i <= 1920*2-1;i++){
            videobuffer[i] = videobuffer[i + 160];
        }
        for(int i = 0;i <= 80*2-1;i++){
            videobuffer[i + 1920*2] = 0;
        }
        tery = 1;
    }
    return 0;
}

int shownum(int pnum){
    char numstk[64];
    int stktop=0;
    int num = pnum;
    while(1){
        numstk[stktop] = num % 10 + 48;
        stktop++;
        if(num < 10)break;
        num /= 10;
    }
    while(stktop){
        stktop--;
        putchar(numstk[stktop]);
    }
    return 0;
}

int shownum16(int pnum){
    puts("0x");
    char *c16 = "0123456789ABCDEF";
    char numstk[64];
    int stktop=0;
    int num = pnum;
    while(1){
        numstk[stktop] = c16[num % 16];
        stktop++;
        if(num < 16)break;
        num /= 16;
    }
    while(stktop){
        stktop--;
        putchar(numstk[stktop]);
    }
    return 0;
}