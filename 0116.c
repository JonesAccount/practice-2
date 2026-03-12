#include <stdio.h>

int main(void) {
    char n1[] = "Sub";
    char n2[] = "way";
    strcpy(n1, n2);
    printf("%s\n%s", n1, n2);
}