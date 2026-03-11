#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void recan(short num);


int main(void) {
    recan(9);
}


bool factor = false;
short counter = 0;
void recan(short num) {
    if (num == 0 || factor == true) {
        printf("+ %hd\n", num);
        factor = true;
        counter++;
        if (counter == 10)
            exit(0);
        recan(num + 1);
        
    }
    else {
        printf("- %hd\n", num);
        recan(num - 1);
    }
}