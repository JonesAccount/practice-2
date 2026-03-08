#include <stdio.h>

int main(void)
{
     float array[2][3] = {
         {4.7f, 76.8f, 9.0f},
         {36.46f, 755.01f, 1.0f}
     };
     
     printf("%.1f\n", array[1][1]);
     printf("%.1f", array[0][2]);
}