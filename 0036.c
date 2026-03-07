#include <stdio.h>

int main(void)
{
     short int nums[3];
     char line_break[] = "\n\n";
     
     printf("Заполни массив только числами%s", line_break);
     printf("#1 | Элемент: ");
     scanf("%hi", &nums[0]);
     printf("#2 | Элемент: ");
     scanf("%hi", &nums[1]);
     printf("#3 | Элемент: ");
     scanf("%hi", &nums[2]);
     
     if (sizeof(nums[1]) == 2 && sizeof(nums[1]) == 2 && sizeof(nums[2]) == 2) {
         printf("%sПравильно, массив из чисел", line_break);
     } else {
         printf("%sНеправильно, массив не из чисел", line_break);
     }
     
     return 0;
}