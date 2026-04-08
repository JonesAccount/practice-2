#include <stdio.h>

#define ON 0b0010
#define OFF 0b0001

char console_param = 0b0010;
       
void func() {
    if (console_param & ON) {
        printf("Console if on | 0b0010");
    } else if (console_param & OFF) {
        printf("Console if off | 0b0001");
    }
    
    static int flag = 1;
    if (flag) {
        console_param = 0b0001;
        flag = 0;
    } else if (!flag) {
        console_param = 0b0010;
        flag = 1;
    }
}

int main(void) {
    printf("\033[?25l");
    
    while (1) {
        func();
        getchar();
    }
    
    return 0;
}