#include <stdio.h>
#define p printf

char brk[] = "\n";
char line[] = "          –––––––––––––";
char space[] = "          ";
char border[] = "––––––––––––––––––––––––––––––––––";


void show(void) {
    p("%s\n", border);
    p("%s    ПОЛКА%s%s", space, brk, brk);
    p("%s|   пусто   |%s", space, brk);
    p("%s%s", line, brk);
    p("%s|   пусто   |%s", space, brk);
    p("%s%s", line, brk);
    p("%s|   пусто   |%s", space, brk);
    p("%s%s", line, brk);
    p("%s|   пусто   |%s", space, brk);
    p("%s\n", border);
    
    p("Команды:%s", brk);
    p("[1] Добавить книгу%s", brk);
    p("[2] Удалить книгу%s", brk);
    p("[3] Наибольший рейтинг%s", brk);
    p("[4] Самая новая книга%s", brk);
    p("[5] Самая старая книга%s", brk);
    p("[6] Завершить программу%s%s", brk, brk);
}