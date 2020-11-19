#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

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
void leitura(int numero)
{
    scanf("%d", &numero);

    if (numero > 0)
    {
        int validador = primos(2, numero);

        if (validador == 1)
        {
            printf("O numero (%d) é primo\n", numero);
        }
        else
        {
            printf("O numero (%d) não é primo\n", numero);
        }
        
      leitura(numero);  
    }
}
int main()
{
    int numero;

    leitura(numero);

    return 0;
}