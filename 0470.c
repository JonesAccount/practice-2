#include <stdio.h>

enum Op {
    ADD,
    MINUS
};

int main(void) {
    enum Op op = MINUS;
    
    switch (op) {
        case ADD: printf("add"); break;
        case MINUS: printf("minus"); break;
        default: printf("another");
    }
    
    return 0;
}