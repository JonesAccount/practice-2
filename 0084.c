#include <stdio.h>

short sum(short *arr);

int main(void) {
    short array[] = {1, 2, 3, 4, 5};
    short * pArray = array;
    short res = sum(pArray);
    printf("%hi", res);
}

short sum(short *arr) {
    short result = 0;
    for (short i = 0; i < 5; i++) {
        result += arr[i];
    }
    return result;
}