/*
n m
	
n < 100
	
*/
#include<stdio.h>
#include<vector>
#include <stack>
#include <list>

using namespace std;

vector<int> g[101];
int vis[101];
stack<int> pilha;
list<int> lista;

//1 4 2 5 3
void mostra(int n){
    	
//	while(!pilha.empty()){	
//		printf("%d ",  pilha.top());
//  	pilha.pop();
//   }
    list<int>::iterator it;
    for(it=lista.begin(); it != lista.end(); it++)
		printf("%d ",  *it); 
	lista.clear();	  
}

void dfs(int u){
	int i;
	vis[u]=1;
		
	for(i=0; i<g[u].size(); i++){
		if(!vis[ g[u][i] ]){
			dfs( g[u][i] );
		}	
    }
    lista.push_front(u);
	//pilha.push(u);
	//printf("%d ",u);
    
}


void ordenacaTopoligica(int n){
	int i;

	for(i=1; i<=n; i++){
		if(!vis[i]){
			dfs(i);
			//lista[tam]=pilha.top();
			//pilha.pop();
			//tam++;
		}
	}
	mostra(n);    
    printf("\n");

}


int main(){
	int n, m, i, j;
	
	while(scanf("%d %d", &n, &m)){
		if(n==0 && m==0)
	   		return 0;
		for(int x=1; x<=n; x++){
			g[x].clear();
			vis[x]=0;
		}
				
		while(m--){
			scanf("%d %d", &i, &j);
			g[i].push_back(j);								
		}
		ordenacaTopoligica(n);
	}	

	return 0;
}

