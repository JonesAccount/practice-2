#include <stdio.h>
    

int main(void) {
    const char *zone = "•";
    short counter = 0;
    
    for (short i = 0; i < 9; i++) {
        printf("%s", zone);
        
        if ((i + 1) % 3 != 0)
            printf(" | ");
        else
            printf("\n");
        
    }
    
}


// • | • | •
// • | • | •
// • | • | •

// • | О | •
// Х | • | •
// • | Х | •

//     1 | 2 | 3
//     —————————
//     4 | 5 | 6
//     —————————
//     7 | 8 | 9

//     1 | 2 | 3
//     4 | 5 | 6
//     7 | 8 | 9