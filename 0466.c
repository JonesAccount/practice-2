#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#define STUDENTS_EXISTS 3

typedef struct {
    char name[50];
    int grade;
    float gpa;
} Student;

char *names[] = {"Philip", "Jon", "Emma", "Dina"};

Student student_create(Student student) {
    strcpy(student.name, names[rand() % 4]);
    student.grade = rand() % 10 + 1;
    student.gpa = 1 + (float)rand() / RAND_MAX * (10 - 1);
    return student;
}

void student_print(Student st) {
    printf("%-8s", st.name);
    printf("%-5d", st.grade);
    printf("%.1f\n", st.gpa);
    
}

void student_upgrade(Student *st) {
    st -> grade++;
    st -> gpa += 0.5;
}

int main() {
    srand(time(NULL));
    
    while (1) {
        Student student[STUDENTS_EXISTS];
    
        // fill
        for (int i = 0; i < STUDENTS_EXISTS; i++) {
            student[i] = student_create(student[i]);
        }
        
        // show
        for (int i = 0; i < STUDENTS_EXISTS; i++) {
            student_print(student[i]);
        }
        
        // updrade
        for (int i = 0; i < STUDENTS_EXISTS; i++) {
            student_upgrade(&student[i]);
        }
        
        // show again
        for (int i = 0; i < STUDENTS_EXISTS; i++) {
            if (!i) { printf("\n"); }
            student_print(student[i]);
        }
        
        (void)getchar();
        system("clear");
    }
    
    return 0;
}