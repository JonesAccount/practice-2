int is_this_word_exist = 1;

int main(void) {
	int index_first_letter_del_word = 0;
	int size_del_word = 0;
	int similar = 0;
	char temp[100];
	int temp_count = 0;
	
	if (!is_this_word_exist) {
		for (int i = 0, j = 0; i < how_many_word_in_dictionary; i++) {
			if (dictionary_list[i] == del_word[j]) {
				if (!j) { index_first_letter_del_word = i; }
	
				j++;
				size_del_word++;
	
				temp[temp_count] = dictionary_list[i];
				temp_count++;
				temp[0] = toupper(temp[0]);
	
				if (!strcmp(temp, del_word)) { break; }
	
				printf("%s -|- %s\n", temp, del_word);
				getchar();
	
			} else {
				index_first_letter_del_word = size_del_word = similar = j = temp_count = 0;
			}
	
			printf("1");
		}
	
	}
}