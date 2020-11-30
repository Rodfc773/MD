#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void preencher(int i, int j, int tamanho, int matriz[tamanho][4])
{
    for (j = 0; j < 2; j++)
    {
        for ( i = 0; i < tamanho; i++)
        {
            if(j == 0)
            {
                printf("Digite um resto para a congruência %d:\n--> ", i + 1);
            }
            else
            {
                printf("Digite um mod para congruência %d:\n--> ", i + 1);
            }
            

            scanf("%d", &matriz[i][j]);
        }
        
    }
}
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
    int q = a/d;
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

    int congruencia = 3;

    int matriz[congruencia][4];

    memset(matriz, 0, sizeof(matriz));

    preencher(0, 0, congruencia, matriz);


    int M = 1;

    for (int i = 0; i < congruencia; i++)
    {
        M = matriz[i][1] * M;
    }
    for (int i = 0; i < congruencia; i++)
    {
        matriz[i][2] = M/matriz[i][1];
    }
    
    for (int i = 0; i < congruencia; i++)
    {
        int tamanho = linhas(matriz[i][2], matriz[i][1], 0);

        int array[tamanho][2];
        long int a, m;

        memset(array, 0, sizeof(array));

        array[tamanho-1][1] = 1;
        a = matriz[i][2];
        m = matriz[i][1];

        for (int j = 0; j < tamanho; j++)
        {
            int q = a/m;
            int r = a%m;

            a = m;
            m = r;

            array[j][0] = q;

            if (r == 0)
            {
                break;
            }
            
        }
        
        calculo(tamanho - 2, tamanho, array, 0);
        
        long int s = array[1][1];

        if((tamanho - 1) % 2 == 0)
        {
            s = s * -1;
        }
        long int x = s;

        if(x > matriz[i][1])
        {
            x = x % matriz[i][1];
        }
        matriz[i][3] = x;

    }
    
    long int Solucao;

    for (int i = 0; i < congruencia; i++)
    {
        Solucao += matriz[i][2] * matriz[i][0] * matriz[i][3];
    }
    
    printf("\n");

    for (int i = 0; i < congruencia; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if(j + 1 == 4)
            {
                printf("%d\n", matriz[i][j]);
            }
            else
            {
                printf("%d ", matriz[i][j]);
            }
            
        }
        
    }
    if (Solucao > M)
    {
        Solucao = Solucao % M;
    }
    
    printf("Solução das congruências é: %ld\n", Solucao);
    return 0;

}
