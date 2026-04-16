#include <stdio.h>

typedef const long int CLI;
typedef long int LI;

CLI N = 10;

int main(void) {
    LI NN[9];
    LI *P = NN;
    *(P) = N;
    {
        CLI N = 20;
        P++;
        *(P) = N;
        {
            CLI N = 30;
            P++;
            *(P) = N;
            {
                CLI N = 40;
                P++;
                *(P) = N;
                {
                    CLI N = 50;
                    P++;
                    *(P) = N;
                    {
                        CLI N = 60;
                        P++;
                        *(P) = N;
                        {
                            CLI N = 70;
                            P++;
                            *(P) = N;
                            {
                                CLI N = 80;
                                P++;
                                *(P) = N;
                                {
                                    CLI N = 90;
                                    P++;
                                    *(P) = N;
                                    {
                                        printf("%ld\n\n", N);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < 9; i++) {
        printf("%ld ", NN[i]);
    }
    
    printf("\n\n%ld", N);
    
    return 0;
}