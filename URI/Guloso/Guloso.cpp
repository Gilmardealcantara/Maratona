#include<stdio.h>
#include<string.h>
#include<algorithm>
#define INF 0x3f3f3f3f
 
using namespace std;
 

    
void print(long long *v, long int in, long int n){
    int i;
    for(i=in; i<n; i++){
        printf("%lld ",v[i]);
    }    
    printf("\n");
}
//fim=tam+1;


long int max(long long *v, long int in, long int fim){
    long int maior=0;
    for(long int i = in; i < fim; i++){
        if(v[i] > v[maior]) maior = i;
    }
    
    return maior;
}

double  substring(long long *v, long int N, long int K){
    long int pos=0;
    double soma=0;
    for(long int i=0; i<=N-K; i++){
        
        if(pos > (i-K)){
            pos=max(v,i,i+K);
            //i=pos;
            //for(int q=pos; q<i+K; i++)
            //    if(v[q] > v[pos]) pos=q;
            //i=pos;
                            
        }else{
            pos=max(v,pos,i+K);
        }
        
            
        soma+=(double)v[pos];
    }
    
    return soma;
}


/*
double  subvetor(long int *v, long int N, long int K){
    long int pos;
    double soma=0;
    long int grupos[10000];
    for(long int i=0; i<N; i++){
        grupos[i]=-INF;
    }
    
    for(long int i=0; i<=N-K; i++){
        print(v, i, i+K);
        for(long int q=i; q > (i+1)-K && q>0 ; q--){
            if(grupos[q] < v[i]) grupos[q]=v[i];
        }
        
    }
    
    for(long int i=0; grupos[i] != -INF; i++)
        soma+=grupos[i];
        
        //soma+=max(v,i,i+K);
    return soma;
}
*/

/* 
void gera(long int pos, long int *v, int *foi, long int n, long int K){
    long int i;
    if(pos==K){
        print(v, K);
        return;
    }
    
        
    for(i=pos+1; i< n; i++){    
        if(!foi[i]){
            foi[i]=1;
            v[pos]=i;
            gera(pos+1, v, foi, n, K);
            foi[i]=0;
        }
    }
}
*/ 
 
int main(){
    int  t, i;
    long int N, K;
    int foi[11];
    long long array[1000000], S;
    

    scanf(" %d", &t);
    while(t--){

        scanf("%ld %ld %lld", &N, &K, &S);
        
        array[0] = S;
        for (i = 1; i < N; ++i)
            array[i] = (1LL*array[i-1]*1103515245 + 12345) % (2147483648LL);

        //N=5;
        //K=3;
         
        //for(i=0; i<N; i++){
        //    array[i] = i;
            //printf("%ld ", array[i]);
        //}
        
        //printf("\n");             
        
        //gera(0, v, foi, N, K);
        printf("%.0lf\n", substring(array, N, K));         

        //printf("\n");
    }
    return 0;
}
