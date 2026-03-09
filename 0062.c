#include <stdio.h>

int main() {
    int i = 1;
    while (!0) {
        printf("%i\n", i);
        i++;
        if (i > 5)
            break;
    }
}