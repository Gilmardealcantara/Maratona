/*Elevador Lotado*/
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

bool cmp(int a, int b){
	return a>b;
}

void mostra(int *v, int n){
	for(int i=1; i<=n; i++)
		printf("%d ", v[i]);
	printf("\n");
}

int main(){
	int T, N, C, M, i, p[50100];
	int soma, maior;

	scanf(" %d", &T);

	while(T--){
		scanf("%d %d %d", &N, &C, &M);
		for(i=1; i<=M; i++)
			scanf("%d ", &p[i]);

		sort(p+1 , p+M+1, cmp);
		
		
		maior=p[1];
		soma=0;
		for(i=1; i<=M; i++){
			if(maior < p[i]) maior = p[i];

			if(!(i%C)){
				soma += maior*2;
				maior = p[i+1];
			}
							
		}
		
		if(M%C)
			soma+=maior*2;
		
		printf("%d\n", soma);
	}	
	
	return 0;
}
