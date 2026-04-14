#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(void) {
	char *str[] = {"legend", "is", "!", "C"};

	printf("%s ", str[3]);
	printf("%s ", *(str + 1));
	printf("%s", *str);
	printf("%s", *(str + 2));

	char *arr = (char *)malloc(strlen(str[0]) * sizeof(char));
	if (NULL == arr) { printf("error"); return 1; }

	for (int i = 0; i < sizeof(arr); i++) {
		arr[i] = *str
	}

	while (*arr != '\0') {
		if (*arr == 'g' && *arr == 'e' && *arr == 'n') {
			printf("%c", *arr);
		}
		arr++;
	}

	(void)getchar();

	return 0;
}
