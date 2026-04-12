#include <stdlib.h>
#include <stdio.h>

int main() {
    printf("\033[?25l");
    
    int a = 1;
    int *p = &a;
    
    *p = *p + 1;
    *p += 1;
    *p *= 3;
    *p /= 3;
    *p -= 2;
    
    printf("%d\n", (*p + 1) * 3);
    
    (*p)++; // 2
    (*p)--; // 1
    printf("%d\n", *p);
    *p = (*p)+++*p; // 3
    printf("%d\n", *p);
    *p += (((*p)--) * ((*p)+++*p));
    printf("%d", *p);
    
    int __ = 4;
    int *_ = &__;
    
    (*_)++; *_ = (((*_)++-*_) * *_ << 2 - (*_-(*_)--)); *_ >>= 10; (*_)++; *_ += 1;
    printf("\n\n%d", *_);
    
    return 0;
}