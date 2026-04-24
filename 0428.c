#include <stdio.h>

void uf(int *p, int size) {
    for (size_t i = 0; i < size; i++) {
        *(p + i) *= 2;
    }
}

void lf(int *p, int size) {
    for (size_t i = 0; i < size; i++) {
        *(p + i) /= 2;
    }
}

int main(void) {
    auto const int size = 5;
    int nums[size] = {2, 3, 4, 5, 6};
    int *p = &nums[0];
    
    for (size_t i = 0; i < size; i++) {
        printf("%d ", *p);
        p++;
        if (i == size - 1) { printf("\n\n"); p -= size; }
    }
    
    uf(nums, size);
    
    for (size_t i = 0; i < size; i++) {
        printf("%d ", *p);
        p++;
        if (i == size - 1) { printf("\n\n"); p -= size; }
    }
    
    lf(nums, size);
    
    for (size_t i = 0; i < size; i++) {
        printf("%d ", *p);
        p++;
        if (i == size - 1) { printf("\n\n"); }
    }
    
    return 0;
}