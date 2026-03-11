#include <stdio.h>

int main(void) {
    short age; short * pAge = &age;
    printf("Возраст: ");
    scanf("%hd", pAge);
    printf("%s", (age >= 18) ? "Совершенолетний" : "Не совершенолетний");
}