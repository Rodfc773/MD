#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int MDC(int a , int d)
{
    int r = a % d;
    int q = a /d;

    if (r == 0)
    {
        printf(" ---> %d = %d * %d  + %d <--> %d = %d - %d * %d\n", a, d, q, r, r, a, d, q);

        return d; 
    }
    else
    {
        printf(" ---> %d = %d * %d  + %d <--> %d = %d - %d * %d\n", a, d, q, r, r, a, d, q);
        a = d;
        d = r;

        return MDC(a, d);
    }
    
}
int main()
{

    while (1)
    {
        int a, d;

        printf("\nInforme 2 numeros inteiros\n\n");

        scanf("%d %d", &a, &d);

        printf("Fazendo os calulos, Aguarde.............\n\n");
        int valor = MDC(a, d);

        printf(" ---> MDC(%d,%d) = %d\n\n",a,d, valor);

        printf("-----------------------------------------------------------------\n\n");

        char opcao[9];

        printf("Deseja continuar?\n\n");

        scanf(" %s", opcao);

        if( (strcmp(opcao,"Sim") == 0 || strcmp(opcao,"SIM") == 0) || (strcmp(opcao,"S") == 0 || strcmp(opcao,"sim") == 0) || strcmp(opcao, "s") == 0 )
        {
            continue;
        }
        else
        {
            break;
        }
        
    }
    return 0;
}
