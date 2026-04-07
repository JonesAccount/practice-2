int main(void) {
    printf("\033[?25l");
    
    char s1[] = {"Bubble "};
    char s2[] = {"tea!"};
    
    memcpy(s1 + strlen(s1), s2, strlen(s2));
    
    printf("%s", s1);
    
    
    getchar();getchar();
    
    char *arr = (char *)malloc(100);
    strcpy(arr, "me this hello");
    
    join(&arr, "mir!");
    
    printf("%s", arr);
    
    
    
    return 0;
}