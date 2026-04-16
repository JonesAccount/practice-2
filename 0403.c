#include <stdio.h>

void main(void)
{
    int a = 2;
    {
        {
            {
                {
                    printf("что! %d", a);
                }
            }
            
            {
                printf("\nЧе происходит");
            }
            
            {
                {
                    int n = 1;
                    for (int i = 1; i <= 5; i++) {
                        n *= i;
                    }
                    printf("\n\n%d", n);
                }
            }
        }
    }
}