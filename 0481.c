#include <stdlib.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <stddef.h>
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
#define LENGTH_WORD 50
#define NLINE "\n"
#define RED "\033[31m"
#define GRAY "\033[90m"
#define RESET "\033[0m"
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
typedef struct {
	char word[LENGTH_WORD];
} St;
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
static void menu_page(void);
static void add_word(St *dictionary);
static int choice_action(void);
static void show_words(St *dictionary, size_t size);
static char getch(void);
static void clear_screen(void);
static void waiting(void);
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
int main(int argc, char *argv[]) {
	printf("\033[?25l");
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	St *dictionary = (St *)malloc(sizeof(St));
	if (NULL == dictionary) { printf("error creating dinameccaly array"); return 1; }

	FILE *file = fopen("dictionary.txt", "r");
	if (NULL == file) { printf("error opening file"); return 1; }

	char ch = 0;
	char buffer[256] = {0};
	int counter = 1;
	while ((ch = getc(file)) != EOF) {
		St *temp = realloc(dictionary, counter * sizeof(St));
		if (NULL == temp) { printf("error creating temp array"); free(dictionary); return 1; }
		dictionary = temp;
		fgets(buffer, sizeof(buffer), dictionary + counter -> word);
		counter++;
	}

	fclose(file);
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	size_t size = 0;

	while (1) {
		menu_page();
		int action = choice_action();

		if (action) { clear_screen(); }
		switch (action) {
			case 1:
				size = sizeof(*dictionary) / sizeof(*(dictionary));
				show_words(dictionary, size);
				waiting();
				break;
			case 2: printf("2"); break;
			case 3: printf("3"); break;
			case 4: printf("4"); break;
			case 5: printf("5"); break;
		}

		clear_screen();
	}

	printf("\033[?25h");
	return 0;
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
static void menu_page(void) {
	static char *menu_choice[] = {"Show words", "Seach a word", "Show letter category", "Add a word", "Delete a word"};
	const size_t size = sizeof(menu_choice) / sizeof(menu_choice[0]);

	printf(RED "ENGLISH " RESET "DICTIONARY" NLINE NLINE);

	for (int i = 0; i < size; i++) {
		printf("[%d] %s" NLINE, i + 1, menu_choice[i]);
	}

	printf(NLINE GRAY "choose the option" RESET);
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
static void add_word(St *dictionary) {
//	St *temp = realloc()
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
static int choice_action(void) {
	static char ch = 0;

	ch = getch();

	switch (ch) {
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
	}

	return 0;
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
static void show_words(St *dictionary, size_t size) {
	for (size_t i = 0; i < size; i++) {
		printf("- %s", *(dictionary + i));
	}
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
static char getch(void) {
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
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
static void clear_screen(void) {
    fputs("\033[2J\033[H", stdout);
    fflush(stdout);
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
static void waiting(void) {
	char ch = getch();
}
