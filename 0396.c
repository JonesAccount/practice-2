#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>

void foo(char *arr, const int SIZE) {
    char el = 0;
    for (int i = 0; i < SIZE; i++) {
        el = *(arr + i);
        
        if (islower(el)) {
            *(arr + i) = toupper(el);
            continue;
        }
        
        if (isupper(el)) {
            *(arr + i) = tolower(el);
        }
        
    }
}

int main(void) {
    printf("\033[?25l");
    srand(time(NULL));
    
    int size = 10;
    char letters[size];
    
    int solver = 0;
    char letter = 65;
    for (size_t i = 0; i < size; i++) {
        solver = rand() % 2;
        letter = rand() % (90 - 65 + 1) + 65;
        
        switch (solver) {
            case 1:
                *(letters + i) = letter;
                break;
            case 0:
                *(letters + i) = tolower(letter);
        }
        
    }
    
    for (size_t i = 0; i < size; i++) {
        printf("%c ", *(letters + i));
    }
    
    printf("\n\n");
    
    void (*foo_pointer)(char *, const int);
    foo_pointer = foo;
    foo_pointer(letters, size);
    
    for (size_t i = 0; i < size; i++) {
        printf("%c ", *(letters + i));
    }
    
    return 0;
}