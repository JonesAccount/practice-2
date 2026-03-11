#include <stdio.h>


int main(void) {
    short n; short * pN = &n;
    char name[10]; char * pName = &name;
    printf("Day: ");
    scanf("%hd", pN);
    
    pName = (*pN == 1) ? "Monday" :
            (*pN == 2) ? "Tuesday" :
            (*pN == 3) ? "Wednesday" :
            (*pN == 4) ? "Thursday" :
            (*pN == 5) ? "Friday" :
            (*pN == 6) ? "Saturday" :
            (*pN == 7) ? "Sunday" :
            "error bitch!";
    
    printf("%s", pName);
}

/*
1 Monday
2 Tuesday
3 Wednesday
4 Thursday
5 Friday
6 Saturday
7 Sunday
*/