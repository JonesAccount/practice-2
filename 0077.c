#include <stdlib.h>
#include "closet.h"
#include "addB.h"

// структура книги
struct Book {
    char title[100];
    char author[50];
    short year;
    float rating;
};
struct Book B1; struct Book B2;
struct Book B3; struct Book B4;

// переменные
short choice, ext = 0;


int main(void) {
    while (1) {
        show();
        printf("$ ");
        scanf("%hi", &choice);
        
        switch (choice) {
            case 1:
                add(B1);
                break;
            case 2:
                getchar(); getchar();
            case 3:
                getchar(); getchar();
            case 4:
                getchar(); getchar();
            case 5:
                getchar(); getchar();
            case 6:
                ext = 1;
                break;
        }
        if (ext) break;
    }
    system("clear");
}