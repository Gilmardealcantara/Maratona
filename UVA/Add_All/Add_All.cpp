#include <stdio.h>
#include <algorithm>
#define TAM 5001

using namespace std;
//heap
int heap[TAM];
/*tamanho a ser lido do teclado*/
int n=0;
/*heap maximo*/
void sobe(int i){
	int p = i/2;
	int tmp;
	/*se o pai for menor que o filho ele sobe o filho*/
	while(i!=1 && heap[p] > heap[i]){
		tmp = heap[p];
		heap[p] = heap[i];
		heap[i]	= tmp;

		i = p;
		p = i/2;
	}
}

void desce(int i){
	int f = 2*i;
	int tmp;

	while(f <= n){
		/*pega o maior filho*/
		if(f<n && heap[f] > heap[f+1] )
			f += 1;
		if(heap[f] >= heap[i])
			break;
		tmp = heap[f];
		heap[f] = heap[i];
		heap[i] = tmp;

		i = f;
		f = 2*i;
	}

}

void constroiS(){
	int i;
	for(i=1; i<= n; i++){
		sobe(i);
	}	
}


void constroi(){
	int i;
	for(i=n/2; i >= 1; i--){
		desce(i);
	}	
}

void insere(int novo){
	heap[n+1] = novo;
	n += 1;
	sobe(n);	

}

int remove(){
	int ele = heap[1];
	heap[1] = heap[n];
	n -= 1;
	desce(1);

	return ele;
}

void mostra(){
	for(int i=1; i<=n; i++)
		printf("%d ", heap[i]);
	printf("\n");
}

int somaP(){
	int i, soma=0, t, peso=0;
    t=n;
		
	for(i=1; n; i++){
        soma = remove();
        soma += remove();
        peso += soma;
        if(n!=0)
            insere(soma); 
        	
	}
	return peso;
}

int main(){
	int N, i, x;
	while(scanf("%d", &N) > 0){
		if(N==0)
			return 0;
		n = N;
		for(i=1; i<=N; i++){
			scanf("%d", &heap[i]);
		}
		constroi();
		
		printf("%d\n", somaP());		
				
	}	
	return 0;
}













