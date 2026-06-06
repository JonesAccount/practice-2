#include <iostream>

int s_index(int *nums, int size, int myNum) {
    int index;
    
    for (int i = 0; i < size; i++) {
        if (nums[i] == myNum) {
            index = i;
            break;
        }
    }
    
    return index;
}

int main() {
    int nums[] = {5, 3, 8, 6, 9, 0};
    int myNum;
    int index;
    
    for (int i = 0; i < sizeof(nums)/sizeof(nums[0]); i++) {
        std::cout << nums[i] << " ";
    }
    
    std::cout << "\n\n";
    
    std::cout << "::";
    std::cin >> myNum;
    
    index = s_index(nums, sizeof(nums)/sizeof(nums[0]), myNum);
     
    std::cout << myNum << " - index: " << index;
    
    return 0;
}