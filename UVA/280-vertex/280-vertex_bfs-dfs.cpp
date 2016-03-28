#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;


vector<int> g[101];
int vis[101];
int cont=0;
void dfs(int x){
    for(int i=0; i<g[x].size(); i++){
        if(!vis[g[x][i]]){ 
            vis[g[x][i]]=1;     
            dfs(g[x][i]);
            cont++;
        }
    }    
}


void bfs(int u){
    
	int i;
	queue<int> fila;
	fila.push(u);
			
				
	while(!fila.empty()){
		u=fila.front();
		fila.pop();
	    
	    for(i=0; i <g[u].size(); i++){
			if( !vis[ g[u][i] ] ){
				vis[ g[u][i] ]= 1;
				fila.push( g[u][i] );
				cont++;
			}	
		}
	}
}

void mostraGrafo(int n){
	int j, i;
	for(i=1; i<=n; i++){
	    printf("%d->",i);
	    for(j=0; j<g[i].size(); j++){
		    printf("%d ", g[i][j]);
		}
        printf("\n");    
    }
	
}


int main(){

	int n, i, e=1, u, b;
	
	while(scanf("%d", &n)){
        if(n==0)
			return 0;
							            	
		int tmp=n;

		for(i=1; i<=n; i++){
		    g[i].clear();
	    	vis[i]=1;
		}
	   
	    
		while(tmp--){
			e=1;
			scanf("%d", &u);
		            
            if(u==0)
               break;
                
			while(scanf("%d", &e)){			
			    if(e==0)
					break;			
				g[u].push_back(e);
			}
		}
		
	    if(u!=0)
    		scanf("%d", &e);				    
		scanf("%d", &b);				
        
		while(b--){            
		    scanf("%d", &e);
         	
         	for(i=1; i<=n; i++){
		        vis[i]= 0;
	        }	        
	        cont=0;
            
	        dfs(e);
			/*bfs(e);*/
            
			printf("%d", n- cont);
			for(i=1; i<=n; i++)
				if(!vis[i])
					printf(" %d", i);
			printf("\n");
		
		}
		
	}

	
	return 0;
}
