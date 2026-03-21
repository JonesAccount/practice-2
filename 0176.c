#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int storage[4] = {0};
int counter = 0, input;

void show(void) {
    printf("%d | %d | %d | %d\n",
    storage[0],
    storage[1],
    storage[2],
    storage[3]);

}

int main(void) {
    printf("Число 0-15: ");
    scanf("%d", &input);
    while (counter != input) {
        show();
        storage[3]++;
        counter++;

        for (int i = 3; i > 0; i--) {
            if (storage[i] == 2) {
                storage[i] = 0;
                storage[i - 1]++;
            }
        }

        if (storage[0] == 2) {
            storage[0] = 0;
        }

        usleep(100000);
        system("clear");
    }
    show();
    printf("%d", input);
}