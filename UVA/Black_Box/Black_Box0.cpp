#include <stdio.h>
#include <algorithm>
#define TAM 30002

using namespace std;
int heapMin[TAM];
int heapMax[TAM];

/*tamanho a ser lido do teclado*/
int nMin=0, nMax=0, I=0;

void sobeMin(int i);
void desceMin(int i);
void sobeMax(int i);
void desceMax(int i);
void constroi();
void insereMax(int novo);
void insereMin(int novo);
void ADD(int novo);
int  GET();
int  removeMin();
int  removeMax();
	
int main(){
    I=0;
    int i, k, N, M, j;
    int A[30002], u[30002];
    
    scanf("%d", &k);
    getchar();
    
    while(k--){
        nMin=0;
        nMax=0;
        I=0;

        scanf("%d %d", &M, &N);
        
        for(i=0; i<M; i++){
            scanf("%d", &A[i]);
            heapMin[i+1]=0;
            heapMax[i+1]=0;            
        }
        
        for(i=0; i<N; i++)
            scanf("%d", &u[i]);
        
        for(i=0, j=0; i < N; j++){
            ADD(A[j]);
            while((j+1) == u[i]){                    
                printf("%d\n",GET()); 
                i++;
            }
        }
        
        if(k != 0 )
            printf("\n");                
    }
	return 0;
}


void ADD(int novo){
    
    if(novo > heapMax[1]){
        insereMin(novo);
	}else{
        insereMax(novo);
    }	
}


int GET(){  
	while(I != nMax){
	    if(I > nMax){
	        insereMax(removeMin());
	    }else if(I < nMax){
	        insereMin(removeMax());     
	    }
	}
	I++;
	
	return heapMin[1];
}

/*--------------------------heaps */

/*heapMin minimo*/
void sobeMin(int i){
	int p = i/2;
	int tmp;
	/*se o pai for menor que o filho ele sobe o filho*/
	while(i!=1 && heapMin[p] > heapMin[i]){
		tmp = heapMin[p];
		heapMin[p] = heapMin[i];
		heapMin[i]	= tmp;

		i = p;
		p = i/2;
	}
}


void desceMin(int i){
	int f = 2*i;
	int tmp;

	while(f <= nMin){
		/*pega o maior filho*/
		if(f<nMin && heapMin[f] > heapMin[f+1] )
			f += 1;
		if(heapMin[f] >= heapMin[i])
			break;
		tmp = heapMin[f];
		heapMin[f] = heapMin[i];
		heapMin[i] = tmp;

		i = f;
		f = 2*i;
	}
}
/*-----------------------------------------*/
/*heap maximo*/
void sobeMax(int i){
	int p = i/2;
	int tmp;
	/*se o pai for menor que o filho ele sobe o filho*/
	while(i!=1 && heapMax[p] < heapMax[i]){
		tmp = heapMax[p];
		heapMax[p] = heapMax[i];
		heapMax[i]	= tmp;

		i = p;
		p = i/2;
	}
}

void desceMax(int i){
	int f = 2*i;
	int tmp;

	while(f <= nMax){
		/*pega o maior filho*/
		if(f<nMax && heapMax[f] < heapMax[f+1] )
			f += 1;
		if(heapMax[f]<= heapMax[i])
			break;
		tmp = heapMax[f];
		heapMax[f] = heapMax[i];
		heapMax[i] = tmp;

		i = f;
		f = 2*i;
	}

}

/*-----------------------------------------*/
    
void insereMax(int novo){
	heapMax[nMax+1] = novo;
	nMax += 1;
	sobeMax(nMax);	

}

void insereMin(int novo){
	heapMin[nMin+1] = novo;
	nMin += 1;
	sobeMin(nMin);	
}


int removeMin(){
	int ele = heapMin[1];
	heapMin[1] = heapMin[nMin];
	nMin -= 1;
	desceMin(1);
    if(nMin==0)
        heapMin[1] = 0;
	return ele;
}

int removeMax(){
	int ele = heapMax[1];
	heapMax[1] = heapMax[nMax];
	nMax -= 1;
	desceMax(1);
    if(nMax==0)
        heapMax[1] = 0;
        
	return ele;
}

