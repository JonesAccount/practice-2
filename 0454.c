#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define RAND rand() % 7

typedef struct {
    char type[50];
    char color[10];
    int rooms;
    float price;
} House;

void fill_struct(House *house, char types, char colors);
void print_struct(House *house);
void clear_screen(void);

int main(int argc, char *argv[]) {
    printf("\033[?25l");
    srand(time(NULL));
    
    char *house_types[] = {"single-family", "detached home", "townhouse", "condo", "apartment", "bungalow", "manufactured home"};
    char *house_colors[] = {"red", "blue", "green", "grey", "yellow", "black", "white"};
    auto bool loop = true;
    
    while (loop) {
        House house;
        
        fill_struct(&house, house_types, house_colors);
        print_struct(&house);
        
        (void)getchar();
        clear_screen();
    }
    
    printf("\033[?25h");
    return 0;
}

void fill_struct(House *house, char types, char colors) {
    strcpy(house -> type, types[RAND]);
    strcpy((*house).color, colors[RAND]);
    house -> rooms = RAND; if (house -> rooms == 0) { house -> rooms++; }
    (*house).price = (rand() % 501 + 500) + (rand() % 100) / 100.f;
} 

void print_struct(House *house) {
    printf("$ House for sale $\n");
    printf("\nType: %s", house -> type);
    printf("\nColor: %s", ((*house).color == "red") ? "\033[31mred\033[0m" : house -> color);
    printf("\nRooms: %d", house -> rooms);
    printf("\nPrice: %.2f$", house -> price);
}

void clear_screen(void) {
    fputs("\033[2J\033[H", stdout);
    fflush(stdout);
}