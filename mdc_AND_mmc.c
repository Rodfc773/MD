#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int fatorar(int i, int a, int b, int valor)
{
    if (a > 1 || b > 1)
    {
        if ( a  % i == 0 && b % i == 0 )
        {   
            
            a = a/i;
            b = b/i;

            valor = valor * i;

            fatorar(2 , a, b, valor);
        }
        else if(a % i == 0)
        {

            a = a/i;

            valor = valor * i;

            fatorar(2 , a, b, valor);
        }
        else if(b % i == 0)
        {

            b = b/i;

            valor = valor * i;

            fatorar(2 , a, b, valor);
        }
        else
        {
            fatorar(i + 1, a, b, valor);
        }      
    }
    else
    {
        return valor;
    }
    
}
int MDC(int a , int d)
{
    int r = a % d;
    int q = a / d;

    if (r == 0)
    {

        return d; 
    }
    else
    {
        a = d;
        d = r;

        return MDC(a, d);
    }
    
}
int main()
{
    int a ,b;

    scanf("%d %d", &a, &b);

    int mmc, mdc;

    mmc = fatorar(2, a, b, 1);
    
    printf("MMC(%d, %d) = %d\n\n", a, b, mmc);
    mdc = MDC(a, b);

    

    printf("MDC(%d, %d) = %d\n",a , b, mdc);

    return 0;
}