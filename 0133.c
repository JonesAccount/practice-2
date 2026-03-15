#include <stdlib.h>
#include <stdio.h>

int main() {
    int bytes;
    
    printf(">>> ");
    scanf("%d", &bytes);
    
    char A[bytes];
    double mb = bytes / (1024.0 * 1024.0);
    printf("Выделено: %f мб.", mb);
    
    
}