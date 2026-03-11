#include <stdio.h>
#include <string.h>


struct Students {
    char name[15];
    short age;
    float grade;
};


int main(void) {
    
    struct Students s1, s2, s3, s4, s5;
    
    strcpy(s1.name, "Алексей");
    s1.age = 20; s1.grade = 4.7;

    strcpy(s2.name, "Мария");
    s2.age = 19; s2.grade = 3.8;

    strcpy(s3.name, "Дмитрий");
    s3.age = 21; s3.grade = 4.9;

    strcpy(s4.name, "Екатерина");
    s4.age = 20; s4.grade = 4.2;

    strcpy(s5.name, "Иван");
    s5.age = 22; s5.grade = 3.5;
    
    float sred = 0;
    sred += s1.grade; sred += s2.grade;
    sred += s3.grade; sred += s4.grade;
    sred += s5.grade; sred /= 5;
    printf("Средний балл: %.1f⭐", sred);
    
    printf("\n\nУмные студенты:\n");
    if (s1.grade >= 4.5)
        printf("• %s\n", s1.name);
    if (s2.grade >= 4.5)
        printf("• %s\n", s2.name);
    if (s3.grade >= 4.5)
        printf("• %s\n", s3.name);
    if (s4.grade >= 4.5)
        printf("• %s\n", s4.name);
    if (s5.grade >= 4.5)
        printf("• %s\n", s5.name);
    
    printf("\nТупые студенты:\n");
    if (s1.grade < 4.5)
        printf("• %s\n", s1.name);
    if (s2.grade < 4.5)
        printf("• %s\n", s2.name);
    if (s3.grade < 4.5)
        printf("• %s\n", s3.name);
    if (s4.grade < 4.5)
        printf("• %s\n", s4.name);
    if (s5.grade < 4.5)
        printf("• %s\n", s5.name);
    
    return 0;
}


/*
Алексей  | 20 лет | Средний балл: 4.7 ⭐ Отличник
Мария    | 19 лет | Средний балл: 3.8
Дмитрий  | 21 лет | Средний балл: 4.9 ⭐ Отличник
Екатерина | 20 лет | Средний балл: 4.2
Иван      | 22 года | Средний балл: 3.5
*/