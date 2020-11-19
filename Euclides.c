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
        printf("%d = %d * %d  + %d <--> %d = %d - %d * %d\n", a, d, q, r, r, a, d, q);

        return d; 
    }
    else
    {
        printf("%d = %d * %d  + %d <--> %d = %d - %d * %d\n", a, d, q, r, r, a, d, q);
        a = d;
        d = r;

        return MDC(a, d);
    }
    
}
int main()
{
    int numero = 1;;

    while (numero != 0)
    {
        int a, d;

        scanf("%d %d", &a, &d);

        int valor = MDC(a, d);

        printf("MDC(a,d) = %d\n", valor);

        scanf("%d", &numero);
    }
    return 0;
}