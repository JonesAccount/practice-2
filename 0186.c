#include <stdio.h>
#include <stdbool.h>

typedef unsigned int uint;
typedef float ft;
typedef bool booling;
typedef unsigned long long int ulli;
typedef short int sint;

int main(void) {
    uint x = 5;
    ft y = 3.5;
    booling z = true;
    ulli c = 33487639457294;
    sint b = 5555;

    printf("%d | %.1f | %d | %lld | %hd", x, y, z, c, b);

    printf("\n\n");

	return 0;
}
