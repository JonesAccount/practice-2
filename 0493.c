#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    while (1) {
        char haystack[] = "Banana Apple Qiwi Melon Orange";
        
        char needle[30] = {0};
        printf("Input: ");
        fgets(needle, sizeof(needle), stdin);
        needle[strcspn(needle, "\n")] = '\0';
        
        char *res = strstr(haystack, needle);
        if (NULL == res) { printf("fail to find"); }
        printf("%s", res);
    
        (void)getchar();
        system("clear");
    }
    return 0;
}