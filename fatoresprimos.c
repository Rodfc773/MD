#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void fatorar(int i, int a)
{
    if (a > 1)
    {
        if (a  %  i == 0)
        {

            printf("%d |%d\n", a, i);
            
            a = a/i;

            

            fatorar(2 , a);
        }
        else
        {
            fatorar(i + 1, a);
        }      
    }
    else
    {
        printf("%d\n", a);
    }
    
}
int main()
{
    int a ,n;

    scanf("%d", &a);

    fatorar(2, a);
    return 0;
}