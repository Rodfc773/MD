#include <stdio.h>

int main() 
{
    int n1, n2;
    //valor base
    int fatores = 2, mmc = 1, mdc = 1;

    printf("Digite um numero: \t");
    scanf("%d", &n1);

    printf("Digite um numero: \t");
    scanf("%d", &n2);

    printf("\n");

    while (n1 + n2 > 2) 
    {
        if (n1 % fatores == 0 && n2 % fatores == 0)
        {
            printf("%d, %d|%d\n", n1, n2, fatores);
            n1 = n1 / fatores;
            n2 = n2 /fatores;
            mmc = mmc * fatores;
            mdc = mdc * fatores;
        }
        
        else if (n1 % fatores == 0) 
        {
            printf("%d, %d|%d\n", n1, n2, fatores);
            n1 = n1 / fatores;
            mmc = mmc * fatores;
        } 
        
        else if (n2 % fatores == 0) 
        {
            printf("%d, %d|%d\n", n1, n2, fatores);
            n2 = n2 / fatores;
            mmc = mmc * fatores;
        }
        else
        {
            fatores++;
        }
    }
    
    printf("1, 1|1\n");
    printf("\nMDC = %d", mdc);
    printf("\nMMC = %d", mmc);
    
    
    return 0;
}