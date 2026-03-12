#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
    const char *word[] = {
        "Meow", "Hello",
        "Good", "Car",
        "Buble", "Johny",
        "Cat", "Airplan",
        "C", "Python"
    };
    srand(time(NULL));
    
    while (1) {
        short in = rand() % 10;
        printf("Word: %s\n", word[in]);
        printf("Len: %d\n", strlen(word[in]));
        usleep(1300000);
        system("clear");
    }
    
    return 0;
}