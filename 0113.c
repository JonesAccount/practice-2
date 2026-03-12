#include <stdio.h>
#include <string.h>

int main(void) {
    const char *word[] = {
        "Meow",
        "Hello",
        "Good",
        "Car"
    };
    
    for (short i = 0; i < 4; i++) {
        printf("%s\n", word[i]);
    }
}