#include <iostream>
#include <ctime>

void fill_array(int *numbers);

int main() {
    srand(time(NULL));
    int numbers[10];
    
    fill_array(numbers);
    
    for (int number : numbers) {
        std::cout << number << " ";
    }
    
    return 0;
}

void fill_array(int *numbers) {
    for (int i = 0; i <= 9; i++) {
        *(numbers + i) = 10;
    }
    
    for (int i = 0; i <= 9;) {
        int temp = rand() % 10;
        bool exist = false;
        
        for (int j = 0; j <= 9; j++) {
            if (temp == numbers[i]) {
                exist = true;
                break;
            }
        }
        
        if (!exist && numbers[i] == 10) {
            *(numbers + i) = temp;
            i++;
        }
    }
}