#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void func() {
    srand(time(NULL));
    short int num = rand() % 10 + 1;
    printf("%hi", num);
}

int main(void) {
    func();
    return 0;
}