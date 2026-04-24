#include <stdio.h>

int main(void) {
    auto int a = 5;
    
    // указатель на константу
    const int *p1 = &a;
    
    // константный указатель
    int *const p2 = &a;
    
    // константный указатель на константу
    const int *const p3 = &a;
    
    return 0;
}