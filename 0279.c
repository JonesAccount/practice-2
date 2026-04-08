#include <stdio.h>

int main(void) {
    printf("\033[?25l");
    
    // Wi-Fi, Bluetooth, GPS, Микрофон
    int status = 0b1001;
    
    if (status & 0b1000) {
        printf("Wi-Fi — on");
    }
    
    if (status & 0b0100) {
        printf("Bluetooth — on");
    }
    
    return 0;
}