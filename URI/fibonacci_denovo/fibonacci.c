#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cont=0;
int fibonacci(int n);

int main()
{
    int n = 40;//35
    int c=1;
    clock_t t1, t2;	


    do{
        c=1;
        do{        
            t1 = clock();
            printf("para %d dias ele tera\n%d possiblidades \n\n",n,fibonacci(n));;
            t2 = clock();
            
            printf("Tempo = %e segundos\n\n----------------------------------------\n",((double)t2 - (double)t1)/(double)CLOCKS_PER_SEC);
        
            c++;    
        }while(c<=4);
        
        printf("\n\n00000000000000000000000000000000000000000000000000\n\n");
        n = n + 5;
    }while(n<=55);
    
    printf("Tempo = %e segundos\n",((double)t2 - (double)t1)/(double)CLOCKS_PER_SEC);

    return 0;
}


int fibonacci(int n)
{
    //printf("numero de recursoes = %d\tvalor de n=%d\n",cont++,n);

    if(n <=2 ) //que dois ja que tem q usar 1235813... e nao 11235813
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);

}
