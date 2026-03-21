#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
    srand(time(NULL));
    fflush(stdout);
    while (1) {
        short len = rand() % 30;
        int arr[len];
        for (int i = 0; i < len; i++)
            arr[i] = rand() % 30;
        int *p = arr;
        printf("\n");
        for (int i = 0; i < len; i++) {
            printf("\t%d. %d\n", i + 1, *p);
            p++;
            usleep(100000);
        }
        system("clear");
    }
    return 0;
}