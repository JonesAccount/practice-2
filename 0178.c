#include <stdio.h>
#include <stdlib.h>

int main(void) {
    unsigned short num = 65535;
    num++;
    printf("%hu", num);
    return 0;
}