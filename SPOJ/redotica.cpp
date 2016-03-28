#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#define INF 0x3f3f3f3f

/*grafo de arestas*/
using namespace std; 

struct aresta{
    int peso;
    int u;
};

vector< aresta > g[101];
int n, m, d[101]; /*vetor de distancias.*/
set< pair<int,int> > r; /*contem as aresta a serem constuidas*/

bool comp(int u, int v){
    return d[u] > d[v];
}


void prim(int u){
    int vis[101], pai[101], i, v;
    vector<int> heap;
    
    /*inicializaçao*/
    for(i=1; i<=n; i++){
        vis[i] = 0;
        pai[i]=-1;
        d[i] = INF;        
    }
    
    r.clear();
    pai[u] = u;
    d[u] = 0; 
        
    /*coloca o povo no heap*/
    for(i=1; i<=n; i++)
        heap.push_back(i);
    /*constroi heap*/
    make_heap(heap.begin(), heap.end(), comp);     
   
    while(!heap.empty()){
        v = heap[0];
        heap.erase(heap.begin());
        vis[v]=1;
        
        /*isere os pontos em q a aresta liga do set*/
        if(v > pai[v])
            r.insert(make_pair(pai[v], v));
        else if(v < pai[v])
            r.insert(make_pair(v, pai[v]));
        
        
        /*ascessa a lista de adjacencia do v*/
        for(i=0; i<g[v].size(); i++){
            /*se nao foi visitado o elemsto y */    
            if( !vis[ g[v][i].u ] ){
                /*se a distancia (peso) for menor q a q ta no vetor de distancis */
                if( g[v][i].peso < d[ g[v][i].u ] ){
                    /*atualiza a distancia*/
                    d[ g[v][i].u ] = g[v][i].peso;
                    /*atualiza o pai*/
                    pai[ g[v][i].u ] = v;
                }
            }
        }
        /*reconstroi o heap*/
        make_heap(heap.begin(), heap.end(), comp); 
    }
   
    
}


int main(){
    int x, y, z, i, t=1;
    set< pair<int, int> >::iterator it;
    
    aresta E;
    while(scanf("%d %d ", &n, &m) ==2){
        if(n==0 && m==0)
            break;
        
        printf("Teste %d\n",t);
        
        for(i=1; i<=n; i++)
            g[i].clear();
            
        for(i=0; i<m; i++){
            scanf("%d %d %d", &x, &y, &z);
            E.peso=z;
            E.u=y;
            g[x].push_back(E);            
            E.u=x;            
            g[y].push_back(E);
        }
        
        prim(1);
        
/*        for(i=1; i<=n; i++){
            printf("%d\t", d[i]);
        }printf("\n");    
*/
        for(it=r.begin(); it != r.end(); it++){
                printf("%d %d\n", it->first, it->second);
        }
            
        printf("\n");
        t++;    
    }    
    return 0;
}
