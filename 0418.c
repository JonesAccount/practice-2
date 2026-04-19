#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
 printf("\033[?25l");
 
 char *word_guess = "world";
 int word_length = strlen(word_guess);
 char indents[20];
 
 char render[word_length];
 for (int i = 0; i < word_length; i++) {
  render[i] = '_';
 }
 
 while (1) {
     switch (word_length) {
         case 3: strcpy(indents, "\n\n\t      "); break;
         case 4: strcpy(indents, "\n\n\t     "); break;
         case 5: strcpy(indents, "\n\n\t    "); break;
         case 6: strcpy(indents, "\n\n\t   "); break;
     }
    
     for (int i = 0; i < word_length; i++) {
         if (!i) { printf("%s", indents); }
         printf("%c ", render[i]);
     }
    
     char letter;
     scanf("%c", &letter);
     for (int i = 0; i < word_length; i++) {
      if (*(word_guess + i) == letter) {
       render[i] = letter;
      }
     }
     
     
     system("clear");
 }
 
 return 0;
}