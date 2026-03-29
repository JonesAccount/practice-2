#include <stdio.h>

void method_1(int *a, int *c);
//void method_2();

int main() {
    int arr[] = {7, 2, 5, 3, 9};
    int counter_steps = 0;
    
    int *a = &arr;
    int *c = &counter_steps;
     
    method_1(a, c);
    //method_2();
    
    return 0;
}

void method_1(int *a, int *c) {
    int len = strlen(*a);
    int new[len] = {0};
    
    for (int i = 0; i < len; i++)
        printf("%d ", new[i]);
}

void method_2() {
    
}