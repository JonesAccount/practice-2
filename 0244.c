#include <stdio.h>

int main() {
    long long a = 1000000000LL * 1000000000;
    printf("%lld\n\n", a);
    
    unsigned int n = 0;
    printf("%u\n", n);
    
    n--;
    printf("%u\n", n);
    
    n++;
    printf("%u", n);
}