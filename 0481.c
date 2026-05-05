#include <termios.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
#define LENGTH_WORD 50
#define NLINE "\n"
#define RED "\033[31m"
#define GRAY "\033[90m"
#define RESET "\033[0m"
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
char *dictionary_list;
size_t how_many_word_in_dictionary = 1;
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
static int init_dictionary(void);
static void menu_page(void);
static int add_word(void);
static int del_word(void);
static int choice_action(void);
static void show_words(void);
static char getch(void);
static void clear_screen(void);
static void waiting(void);
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
int main(int argc, char *argv[]) {
	printf("\033[?25l");
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	dictionary_list = malloc(0);
	if (NULL == dictionary_list) { printf("error creating dinameccaly array"); return 1; }

	init_dictionary();

	while (1) {
		menu_page();

		int action = 0;
		action = choice_action();

		if (action) { clear_screen(); }

		switch (action) {
			case 1:
				show_words();
				waiting();
				break;
			case 2: printf("2"); break;
			case 3: printf("3"); break;
			case 4:
				add_word();
				break;
			case 5:
				del_word();
				break;
		}

		clear_screen();
	}

	printf("\033[?25h");
	return 0;
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
static int init_dictionary(void) {
	FILE *file = fopen("dictionary.txt", "r");
	if (NULL == file) { printf("error opening file"); return -1; }

	*(dictionary_list + how_many_word_in_dictionary - 1) = '-';
	how_many_word_in_dictionary++;
	*(dictionary_list + how_many_word_in_dictionary - 1) = ' ';
	how_many_word_in_dictionary++;

	char ch = 0;
	while ((ch = getc(file)) != EOF) {
		char *temp = realloc(dictionary_list, how_many_word_in_dictionary);
		if (NULL == temp) { printf("error creating temp array"); free(dictionary_list); return -1; }
		dictionary_list = temp;

		if (isalpha(ch)) {
			*(dictionary_list + how_many_word_in_dictionary - 1) = ch;
		} else {
			*(dictionary_list + how_many_word_in_dictionary - 1) = '\n';
			how_many_word_in_dictionary++;
			*(dictionary_list + how_many_word_in_dictionary - 1) = '-';
			how_many_word_in_dictionary++;
			*(dictionary_list + how_many_word_in_dictionary - 1) = ' ';
		}

		how_many_word_in_dictionary++;
	}

	fclose(file);
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
static int add_word(void) {
	char new_word[100] = {0};

	while (1) {
		printf("New word: ");
		fgets(new_word, sizeof(new_word), stdin);

		// word or no
		int is_it_word = 1;
		for (int i = 0; i < strlen(new_word) - 1; i++) {
			if (!isalpha(new_word[i])) {
				is_it_word = 0;
				break;
			}
		}

		// exists or no
		FILE *file = fopen("dictionary.txt", "r");
		if (NULL == file) { printf("error"); return -1; }

		int is_this_word_exist = 0;
		char ch = 0;

		char line[100];

		while (fgets(line, sizeof(line), file) != NULL) {
			if (!strcmp(line, new_word)) { is_this_word_exist = 1; }
		}

		fclose(file);

		if (!is_this_word_exist) {
			file = fopen("dictionary.txt", "a");
			if (NULL == file) { printf("error"); return -1; }

			*(dictionary_list + how_many_word_in_dictionary - 1) = '\n';
			how_many_word_in_dictionary++;
			*(dictionary_list + how_many_word_in_dictionary - 1) = '-';
			how_many_word_in_dictionary++;
			*(dictionary_list + how_many_word_in_dictionary - 1) = ' ';
			how_many_word_in_dictionary++;

			for (int i = 0; i < strlen(new_word); i++) {
				putc(new_word[i], file);
			}

			fclose(file);
		}

		clear_screen();
	}

}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
static int del_word(void) {
	char del_word[100];

	while (1) {
		printf("delete word: ");
		fgets(del_word, sizeof(del_word), stdin);

		// find the word
		FILE *file = fopen("dictionary.txt", "r");
		if (NULL == file) { printf("error"); return -1; }

		int is_this_word_exist = 0;
		char ch = 0;
		char line[100];

		while (fgets(line, sizeof(line), file) != NULL) {
			if (!strcmp(line, del_word)) { is_this_word_exist = 1; }
		}

		fclose(file);

		// write code in the down
		if (!is_this_word_exist) {
			file = fopen("dictionary.txt", "a");
			if (NULL == file) { printf("error"); return -1; }

			*(dictionary_list + how_many_word_in_dictionary - 1) = '\n';
			how_many_word_in_dictionary++;
			*(dictionary_list + how_many_word_in_dictionary - 1) = '-';
			how_many_word_in_dictionary++;
			*(dictionary_list + how_many_word_in_dictionary - 1) = ' ';
			how_many_word_in_dictionary++;

			for (int i = 0; i < strlen(new_word); i++) {
				putc(new_word[i], file);
			}

			fclose(file);
		}

		
	}

	return 0;
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
static void show_words(void) {
	for (int i = 0; i < how_many_word_in_dictionary; i++) {
		printf("%c", *(dictionary_list + i));
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
