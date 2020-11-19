#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int primos(int counter, int numero)
{
    if(counter > sqrt(numero) || numero == 2)
    {
        return 1;
    }
    if (numero % counter == 0 || numero == 1)
    {
        return 0;
    }
    else
    {
        return primos(counter + 1, numero);
    }
    
}
int main()
{
    
    clock_t inicio = clock();
    clock_t final = clock();

    int diferenca = 1;
    int i = 1;
    int qtd = 0;

    

    while (diferenca < 60)
    {
        diferenca = (final - inicio)/CLOCKS_PER_SEC;

        if(primos(2, i))
        {
            qtd += 1;
            printf("(%d) é primo\n", i);
        }
        i += 1;


        final = clock();

        
    }
    printf("Esse programa printou %d numeros primos\n", qtd);
    return 0;
}