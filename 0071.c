#include <stdio.h>
#include <unistd.h>

int main(void) {
    int arr[15] = {0};
    short int counter = 0;
    fflush(stdout);
    usleep(90000);
    
    for (short int i = 0; i < 15; i++) {
        counter++;
        switch (counter) {
            case 5:
                printf("%i\n", arr[i]);
                counter = 0;
                break;
            default:
                printf("%i", arr[i]);
        }
        fflush(stdout);
        usleep(90000);
    }   
}