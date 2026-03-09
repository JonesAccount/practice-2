#include <stdio.h>

int main() {
    
    short int nums[] = {56, 8, -4, 688, 0, 1, 99}, size = 7;
    
    for (short int i = 0; i < size; i++) {
        printf("Элемент %hi: %hd\n", i + 1, nums[i]);
    }
    
}