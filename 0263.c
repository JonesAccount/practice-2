#include <stdlib.h>
#include <stdio.h>

void join(char *st1, char *st2) {
    size_t size_st1 = strlen(st1);
    size_t size_st2 = strlen(st2);
    
    char *tmp = realloc(st1, (size_st1 + size_st2 + 1) * sizeof(char));
    if (NULL == tmp) { free(st1); exit(1); }
    
    st1 = tmp;
    
    size_t new_size_st1 = size_st1 + size_st2;
    
    int index = 0;
    for (size_t i = size_st1; i < new_size_st1; i++) {
        st1[i] = st2[index];
        index++;
    }
    
}

int main(void) {
    printf("\033[?25l");
    char *string_1, *string_2;
    
    string_1 = (char *)malloc(sizeof(char) * 8);
    if (NULL == string_1) { return 1; }
    
    string_2 = (char *)malloc(sizeof(char) * 6);
    if (NULL == string_2) { return 1; }
    
    strcpy(string_1, "C - is ");
    strcpy(string_2, "cool!");
    
    join(string_1, string_2);
    
    printf("%s", string_1);
    
    return 0;
}