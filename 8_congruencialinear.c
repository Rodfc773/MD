#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int MDC(int a, int d)
{
    int q = a / d;
    int r = a % d;

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
int linhas(int a, int d, int tamanho)
{
    int r = a % d;
    tamanho += 1;

    if(r == 0)
    {
        return tamanho;
    }
    else
    {
        a = d;
        d = r;

        return linhas(a, d, tamanho);
    }
    
}
void calculo(int i, int tamanho, int matriz[tamanho][2], int anterior)
{
    if (i >= 0)
    {
        if(i == tamanho - 2)
        {
            anterior = 1;

            matriz[i][1] = matriz[i][0] * matriz[i + 1][1];
        }
        else
        {
            matriz[i][1] = matriz[i][0] * matriz[i + 1][1] + anterior;
            anterior = matriz[i + 1][1];
        }
        
        calculo(i - 1, tamanho, matriz, anterior);
    }
}
int main()
{
    long int a,b,m;

    printf("Digite um a:\n--> ");

    scanf("%ld", &a);

    printf("Digite um b:\n--> ");

    scanf("%ld", &b);

    printf("Digite um m:\n--> ");

    scanf("%ld", &m);

    printf("\nAguarde enquanto encontramos uma solução para a congruência %ldx ≡ %ld (mod %ld)......\n", a, b, m);

    int mdc = MDC(a,m);

    if(b % mdc != 0)
    {
        printf("Não há soluções para essa congruência\n");
    }
    else
    {
        a = a/mdc;
        b = b/mdc;
        m = m/mdc;

        int a1, m1;
        int tamanho = linhas(a, m, 0);
        int matriz[tamanho][2];

        memset(matriz, 0, sizeof(matriz));

        matriz[tamanho-1][1] = 1;

        a1 = a;
        m1 = m;

        for (int i = 0; i < tamanho; i++)
        {
            int r = a % m;
            int q = a / m;

            a = m;
            m = r;

            matriz[i][0] = q;

            if (r == 0)
            {
                break;
            }
            
        }
        calculo(tamanho - 2, tamanho, matriz, 0);
        
        int s = matriz[1][1];

        if ((tamanho - 1) % 2 == 0)
        {
             s =  matriz[1][1] * -1;
        }
    
        int x = b * s;

        if (x > m1)
        {
            x = x % m1;

            printf("A solução/soluções da congruência são/é: ");

            for (int g = 0; g < mdc; g++)
            {   
                if(mdc > 1)
                {
                    x += m1;
                }
                if (g + 1 == mdc)
                {
                    printf("%d\n", x);
                }
                else
                {
                    printf("%d, ", x);
                }  
                
            } 

            printf("Podendo ser reescrita como %d + %d * k, com k ∈ ℤ", x, m1);
        }
        else
        {
            printf("A solução/soluções da congruência são/é: ");

            for (int g = 0; g < mdc; g++)
            {
                if (mdc > 1)
                {
                    x += m1;
                }
                
                if (g + 1 == mdc)
                {
                    printf("%d\n", x);
                }
                else
                {
                    printf("%d, ", x);
                }     
            }
            
            printf("Podendo ser reescrita como %d + %d * k, com k ∈ ℤ", x, m1);
        }
        
    }
    
    return 0; 
}
