#include <stdio.h>

int main(void) {
	char *str = {"abracadabra"};

	while (*str != '\0') {
		if (*str != 'a') {
			printf("%c ", *str);
		}
		str++;
	}

	return 0;
}
