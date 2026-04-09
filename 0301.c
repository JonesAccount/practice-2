#include <termios.h>
#include <unistd.h>
#include <stdio.h>

#define WAIT (void)getchar(); (void)getchar();

typedef unsigned int unint;

void generation_and_or_xor(int mode);
void generation_shifts(void);
void clearing_buffer(void);
void generation_not(void);
void clear_screen(void);
void printBinary(int n);
void render_menu(void);
char getch(void);

int main(void) {
    printf("\033[?25l");
    
    char running = 0b0001;
    
    while (running) {
        
        clear_screen();
        render_menu();
        
        char choice = 0;
        choice = getch();
        
        clear_screen();
        switch (choice) {
            case '1':
                  generation_and_or_xor(1);
                  break;
            case '2':
                  generation_and_or_xor(0);
                  break;
            case '3':
                  generation_not();
                  break;
            case '4':
                  generation_and_or_xor(2);
                  break;
            case '5':
                  generation_shifts();
                  break;
            case '6':
                  running = 0b0000;
        }
        
    }   
    
    printf("exit...");
    return 0;
}

void generation_and_or_xor(int mode) {
    switch (mode) {
        case 1: printf("Побитовое И"); break;
        case 0: printf("Побитовое ИЛИ"); break;
        case 2: printf("Исключающее ИЛИ");
    }
    
    printf("\n\n");
    
    int nums[] = {0, 0};
    
    for (int i = 0; i < 2;) {
        printf("Число %s: ", (i == 0) ? "x" : "y");
        scanf("%d", &nums[i]);
        
        if (sizeof(nums[0]) == 4) { i++; }
        
    }
    
    clear_screen();
    printf("Число х: %d | 0b", nums[0]);
    printBinary(nums[0]);
    printf("Число y: %d | 0b", nums[1]);
    printBinary(nums[1]);
    
    int result = 0;
    switch (mode) {
        case 1: result = nums[0] & nums[1]; break;
        case 0: result = nums[0] | nums[1]; break;
        case 2: result = nums[0] ^ nums[1];
    }
    
    printf("\nРезультат: %d | 0b", result);
    printBinary(result);
    
    WAIT
}

void generation_not(void) {
    int x = 0;
    
    printf("Побитовое НЕ\n\n");
    
    while (1) {
        printf("Число: ");
        scanf("%d", &x);
        if (sizeof(x == 4)) { break; }
    }
    
    clear_screen();
    printf("Число: %d | 0b", x);
    printBinary(x);
    unint result = ~x;
    printf("\nРезультат: %u | 0b", result);
    printBinary(result);
    
    WAIT
}

void generation_shifts(void) {
    char choice;
    int number, shift;
    number = choice = shift = 0;
    
    printf("Сдвиги\n\n");
    
    while (1) {
        printf("Число: ");
        scanf("%d", &number);
        if (sizeof(number == 4)) { break; }
    }
    
    printf("\n");
    
    clearing_buffer();
    
    while (1) {
        printf("[1] Влево (<<)\n[2] Вправо (>>)");
        choice = getch();
        if (choice == '1' || choice == '2') { break; }
    }
    
    printf("\n\n");
    
    while (1) {
        printf("Сдвиг: ");
        scanf("%d", &shift);
        if (sizeof(shift == 4)) { break; }
    }
    
    clear_screen();
    printf("Операция: %d %s %d", number, (choice == '1') ? "<<" : ">>", shift);
    printf("\nРезультат\nДо: %d | 0b", number);
    printBinary(number);
    
    switch (choice) {
        case '1': number <<= shift; break;
        case '2': number >>= shift;
    }
    
    printf("После: %d | 0b", number);
    printBinary(number);
  
    
    WAIT
}

void clearing_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void clear_screen(void) {
    printf("\033[2J");  
    printf("\033[H");   
    fflush(stdout);     
}

void printBinary(int n) {
    int i;
    for (i = 3; i >= 0; i--) {
        int bit = (n >> i) & 1; 
        printf("%d", bit);
    }
    printf("\n");
}

void render_menu(void) {
    char *menu[] = {"Побитовые операции\n",
                        "[1] Побитовое И (&, AND)",
                        "[2] Побитовое ИЛИ (|, OR)",
                        "[3] Побитовое НЕ (~, NOT)",
                        "[4] Исключающее ИЛИ (^, XOR)",
                        "[5] Сдвиги (<<, >>)",
                        "[6] Выход"};  
        
    size_t size = sizeof(menu) / sizeof(menu[0]);
        
    for (size_t i = 0; i < size; i++) {
        printf("%s\n", menu[i]);
    }
}

char getch(void) {
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);       
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);    
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); 
    return ch;
}