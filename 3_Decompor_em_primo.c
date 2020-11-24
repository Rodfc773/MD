#include <stdio.h>

int main() 
{
    int numero;
    //valor base
    int fator = 2;

    printf("Digite um numero: \t");
    scanf("%d", &numero);

    printf("\n");

    while (numero > 1) 
    {
        if (numero % fator == 0) 
        {
            printf("%d|%d\n", numero, fator);
            numero = numero / fator;
        } 
        else
        {
            fator++;
        }
    }
    
    printf("1|1\n");
    
    return 0;
}