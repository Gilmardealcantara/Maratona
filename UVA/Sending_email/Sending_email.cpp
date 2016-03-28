/*
2 <= n <= 20000
0 <= m <= 50000
S T 

u = indice 
v = first
w = second
*/

#include <stdio.h>
#include <vector>
#include <utility>
#define INF 0x3f3f3f3f
#define TAM 20000


using namespace std;
vector< pair<int, int> > g[20002];
int W[20002]; /*garda a latencia "caminho" minima para cada no*/

int pos[20002];
int heap[TAM+1];
int nHeap=0; /*controla o heap*/

void mostra(int n); 
void init(int n);
void dijkstra(int s);

void sobe(int i);
void desce(int i);
void constroi();
int remove();
void mostraheap();

int main(){
	int N, n, m, S, T, w, u, v, c=1;
	
	scanf("%d", &N);
	
	while(c<=N){
	    
	    scanf("%d %d %d %d", &n, &m, &S, &T);
	    init(n);

	    S++;T++;
	    while(m--){
	        scanf("%d %d %d", &u, &v, &w);
	        u++; v++;
	        
	        g[u].push_back(make_pair(v,w));
	        g[v].push_back(make_pair(u,w));    
	    }
	    dijkstra(S);
	    
	    if(W[T] != INF){
	        printf("Case #%d: %d\n", c++, W[T]);
	    }else
	    printf("Case #%d: unreachable\n", c++);
	}
	
	      
}

void dijkstra(int s){
    W[s] = 0;
        
    constroi();
    
    //int n = nHeap;
    //mostra(n);
    //mostraheap();
     
    while(nHeap > 0 ){
        s = remove();
        
        for(int i=0; i < g[s].size(); i++){
            if( W[ g[s][i].first ] > g[s][i].second + W[s] ){
                W[ g[s][i].first ] = g[s][i].second + W[s];
                //constroi();    
            //mostraheap();      
                desce( pos[ g[s][i].first ] );
                /*mudar a prioridade*/
            }
        } 
    }
      
}

void mostra(int n){
    for(int i=1; i <= n; i++){
        printf("%d -> ", i);
        for(int j=0; j < g[i].size(); j++){
            printf("%d/%d ", g[i][j].first, g[i][j].second);
        }
        printf("\n");
    }
    printf("\n");
}

void init(int n){
    for(int i=1; i<=n; i++){
        g[i].clear();
        W[i]=INF;
        heap[i]=i;
    }
    nHeap=n;   
}

/*----------------------------------------------------------------------*/
/*heapmin sobrecarregado com W[] para comparacoes*/
void sobe(int i){
	int p = i/2;
	int tmp;
	/*se o pai for menor que o filho ele sobe o filho*/
	while(i!=1 && W[p] > W[i]){
		    
		tmp = heap[p];
        heap[p] = heap[i];
		heap[i]	= tmp;
		  
        pos[ heap[p] ] = p;
        pos[ heap[i] ] = i;		  
                
		i = p;
		p = i/2;
	}
}

void desce(int i){
    int f = 2*i;
	int tmp;

	while(f <= nHeap){
		/*pega o maior filho*/
		if(f < nHeap && W[f] > W[f+1] )
			f += 1;
		if(W[f] >= W[i])
			break;		
		tmp = heap[f];
		heap[f] = heap[i];
		heap[i] = tmp;

        pos[ heap[f] ] = f;
        pos[ heap[i] ] = i;		

		i = f;
		f = 2*i;
	}

}

void constroi(){
	int i;
	for(i=nHeap/2; i >= 1; i--){
		desce(i);
	}
	
	/*garda posiçao dos lelementos no heap*/
    for(int i=1; i<=nHeap; i++)
        pos[ heap[i] ] = i;	
}

int remove(){
	int ele = heap[1];
	heap[1] = heap[nHeap];
	nHeap -= 1; 
	desce(1);

	return ele;
}

void mostraheap(){
	for(int i=1; i<=nHeap; i++){
		    printf("%d (%d) \n", heap[i], W[i]);
	}
	printf("\n");
	/*for(int i=1; i<=nHeap; i++){
		    printf("%d ", pos[i]);
	}
	printf("\n");	
	*/
}


