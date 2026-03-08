#include <stdio.h>
#include <stdlib.h>


void cler() {
    system("clear");
}


int up(short int num) {
    num++; cler();
    return num;
}


int down(short int num) {
    num--; cler();
    return num;
}


int classic(short int num) {
    num = 0; cler();
    return num;
}


int main() {
    short int num = 0, choi;
    const char brk[] = "\n";
    
    while (1) {
        printf("Статус числа: %hi%s%s", num, brk, brk);
        printf("[1] Увеличить%s", brk);
        printf("[2] Уменьшить%s", brk);
        printf("[3] По умолчание%s", brk);
    
        printf(">>> ");
        scanf("%hi", &choi);
    
        switch (choi) {
            case 1:
                num = up(num);
                break;
            case 2:
                num = down(num);
                break;
            case 3:
                num = classic(num);
                break;
            default:
                cler();
        }     
    }
    
    return 0;
}