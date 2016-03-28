#include <stdio.h>
#include <queue>
#include <stack>
#define TAM 1002

using namespace std;
//heap
int heap[TAM];
/*tamanho a ser lido do teclado*/
int n;
/*heap maximo*/
void sobe(int i){
	int p = i/2;
	int tmp;
	/*se o pai for menor que o filho ele sobe o filho*/
	while(i!=1 && heap[p] < heap[i]){
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
		if(f<n && heap[f] < heap[f+1] )
			f += 1;
		if(heap[f] <= heap[i])
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


int main(){
	int teste, a, b;
	queue<int> fila;
	stack<int> pilha;
	bool p, f, h;

	while(scanf("%d", &teste) > 0){
		while(!fila.empty())
			fila.pop();
		while(!pilha.empty())
			pilha.pop();
		
		n=0;/*limpa o heap*/
		
		p = 1; f = 1;  h = 1;

		while(teste--){
			scanf("%d %d", &a, &b);
			
			if(a==1){
				insere(b);
				pilha.push(b);
				fila.push(b);	
			}else if(a==2){
			    /*verificar se as estruturas estao vazioas*/
			    
			       	
				if(n > 0){
				    if(remove() != b)
				        h=0;					    
				}else{
				    h=0;
				}		
			        
			    if(!pilha.empty()){
				    if(pilha.top() != b)
				        p=0;
				    pilha.pop();
				}else{
                    p=0;
                }    
                    
                if(!fila.empty()){    
                    if(fila.front() != b)
				        f=0;
				    fila.pop();
				}else{
				    f=0;
				}    
			}		
		}
		
		if(h==1 && p==0 && f==0)	
			printf("priority queue\n");
		else if(h==0 && p==1 && f==0)	
			printf("stack\n");
		else if(h==0 && p==0 && f==1)	
			printf("queue\n");
		else if(h==0 && p==0 && f==0)	
			printf("impossible\n");
		else	
			printf("not sure\n");
	}
		
	return 0;
}

