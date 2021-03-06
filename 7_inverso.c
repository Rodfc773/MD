#include <stdio.h>
#include <math.h>

int coeficientes(int a[], int i, int b, int d, int c[], int p, int q)
{
    c[0] = 1;

    if(b >= i)
    {
        if(i % 2 == 0)
        {
            c[i - 1] = c[i - 1] * (-1);
            c[i - 2] = c[i - 2];

        }
        else
        {
            c[i - 1] = c[i - 1];
            c[i - 2] = c[i - 2] * (-1);
        }
        
        if(p <= q)
        {
            printf("O inverso da congruência é: %i\n", c[i - 1]);
        }
        else if(p > q)
        {
            printf("O inverso da congruência é: %i\n",c[i - 2]);
        }

    }
    else if(b <= 0)
    {
        c[b + 1] = a[(i-b) - 1] * d + 0;

        d = c[b + 1];

        return coeficientes(a, i, b + 1, d, c, p, q);
    }
    else if(b == 1)
    {
        c[b + 1] = a[(i-b) - 1] * d + c[b];

        d = c[b + 1];

        return coeficientes(a, i, b + 1, d, c, p, q);
    }
    else
    {
        c[b + 1] = a[(i-b) - 1] * d + c[b - 1];

        d = c[b + 1];

        return coeficientes(a, i, b + 1, d, c, p, q);
    }
     

}
int MDC(int x, int y, int i, int vq[], int p, int q)
{
    int maior, menor, mdc, quociente, resto; 

    vq[0] = 0;

    if(x >= y)
    {
        maior = x;
        menor = y;
        quociente = x / y;
        resto = x % y;
    }
    else 
    {
        maior = y;
        menor = x;
        quociente = y / x;
        resto = y % x;
    }


    if(resto == 0)
    {
        int c[10000];
        return coeficientes(vq, i, 0, 1, c, p, q);
    }
    else
    {   
        vq[i] = quociente;
        return MDC(menor, resto, i + 1, vq, p, q);
    }

}
int main()
{
    int a, m;
    printf("insira os valores de 'a' e 'm' respectivamente.\n");
    scanf("%i%i", &a, &m);
    int vq[10000];
    MDC(a, m, 1, vq, a, m);
    
    return 0;
}

