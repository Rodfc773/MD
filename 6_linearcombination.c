#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int MDC(long int a , long int d, int valor, int a1, int d1)
{
    int r = a % d;
    int q = a / d;
    valor += 1;

    if (r == 0)
    {
        printf(" ---> %ld = %ld * %d  + %d <--> %d = %ld - %ld * %d\n", a, d, q, r, r, a, d, q);

        printf("\n ---> MDC(%d, %d) = %ld\n\n", a1, d1, d);
        return valor; 
    }
    else
    {
        a = d;
        d = r;

        printf(" ---> %ld = %ld * %d  + %d <--> %d = %ld - %ld * %d\n", a, d, q, r, r, a, d, q);

        return MDC(a, d, valor, a1, d1);
    }
    
}
void calculo(int i, int tamanho, int matriz[tamanho][2], int anterior)// faz o calculo, se baseando em uma tabela, porem é feito de tras pra frente na matriz
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
    long int a,d;
    long int a1, d1;

    printf("\nDigite dois numeros:\n");

    scanf("%ld %ld", &a, &d);

    printf("\n");

    if(d == 0) // condição colocada para evitar que o programa faça divisões por 0 e "exploda a memória"
    {
        printf("O MDC(%ld, %ld) = 1 * %ld + %ld * 0", a, d, a, d);
    }
    else
    {
            a1 = a;
        d1 = d;

        int tamanho = MDC(a, d, 0,a1, d1);

        tamanho = tamanho;

        int matriz[tamanho][2];

        memset(matriz, 0, sizeof(matriz));    

        matriz[tamanho-1][1] = 1;

        for (int i = 0; i < tamanho; i++)// adiciona os resultados da divisão na  coluna[0] da matriz
        {
            int q = a / d;
            int r = a % d;

            a = d;
            d = r;

            matriz[i][0] = q;

            if(r == 0)
            {
                break;
            }
        }
        calculo(tamanho - 2, tamanho, matriz, 0);

        for (int j = 0; j < tamanho; j++)// printa a matriz, essa parte é caso de algum bug
        {
            for (int z = 0; z < 2; z++)
            {
                if (z + 1 == 2)
                {
                    printf("%d\n", matriz[j][z]);
                }
                else
                {
                    printf("%d ", matriz[j][z]);
                }
                
            }
            
        }
        printf("\n");

        int s, t;

        s = matriz[1][1];
        t = matriz[0][1];

        if (tamanho == 1)// essa condição foi colocada para evitar bugs quando a matriz so tiver uma linha
        {
            if(a1 == 0)
            {
                s = 0;
            }
            else if(d1 == 0)
            {
                t = 0;
            }
            else if (a1 > d1)
            {
                s = 0;
                t = 1;
            }
            else
            {
                t = 0;
                s = 1;
            }
            
            
        }
        else
        {
            if ((tamanho - 1) % 2 == 0)
            {
                s = s * -1;
            }
            else
            {   
                t = t * -1;
            }
        }
        
        
        printf("O MDC de %ld e %ld, pode ser reescrito como:\n\n", a1, d1);
        printf("MDC(%ld, %ld) = (%d) * %ld + (%d) * %ld\n", a1, d1, s, a1, t, d1);

    }
    
   return 0;
}
