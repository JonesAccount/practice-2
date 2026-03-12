#include <stdio.h>
#include <string.h>

int main(void) {
    char n1[] = "Sub";
    char n2[] = "way";
    strcat(n1, n2);
    printf("%s", n1);
}