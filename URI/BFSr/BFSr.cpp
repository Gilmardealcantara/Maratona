//bfs com matriz de adj

#include<bits/stdc++.h>

int lbl[21], cnt=0, V, E;

int adj[21][21], temAdj=0;

void pathR(int v, int cnt){
	int w;
	lbl[v] = cnt++;
	
	for(w=0; w < V; w++){
		if(adj[v][w] == 1){
			temAdj=1;	
			for(int i=0; i<cnt; i++) printf("  ");

			if(lbl[w]==-1){
				printf("%d-%d pathR(G,%d)\n",v, w, w);
				pathR(w, cnt);
			}else{;
				printf("%d-%d\n",v, w);
			}		
		}
	}
}


void init(){
	cnt=0;
	for(int i=0; i<V; i++){
		lbl[i]=-1;
		for(int j=0; j<V; j++){
			adj[i][j]=0;	
		}
	}
}

int main(){
	int t, caso=1, i, v, u;
		
	scanf(" %d", &t);

	while(caso<=t){
		scanf(" %d %d", &V, &E);
		
		init();

		for(i=0; i<E; i++){
			scanf(" %d %d", &v, &u);
			adj[v][u]=1;
		}	
		
		printf("Caso %d:\n", caso++);
		for(i=0; i<V; i++){
			if(lbl[i]==-1){
				cnt=0;
				temAdj=0;
				pathR(i, cnt);
				if(temAdj)//verificar adj pra dar /n
					printf("\n");				
			}
		}
	}
	return 0;
}


