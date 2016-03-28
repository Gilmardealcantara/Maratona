#include<stdio.h>
#define INF 0x3f3f3f3f
/*0 a n-1*/
struct arestas{
    int x, y, t;
};

arestas E[2001];
int t[1001]; 
bool  bellmanFord(int s, int n, int m){
    int i, j;
    for(i=0; i<n; i++)
        t[i]=INF;
    t[s]=0;
    
    for(i=0; i<n-1; i++){
        for(j=0; j<m; j++){
            if( t[ E[j].x ] > t[ E[j].y ] + E[j].t ){
                t[ E[j].x ] = t[ E[j].y ] + E[j].t;
            }
        }   
    }
    for(j=0; j<m; j++)
        if( t[ E[j].x ] > t[ E[j].y ] + E[j].t )
            return false;
    
    return true;
             
}

int main(){

    int c, n, m, i;
    
    scanf("%d ", &c);
    
    while(c--){
        scanf("%d %d", &n, &m);
        for(i=0; i<m; i++)
            scanf("%d %d %d", &E[i].x, &E[i].y, &E[i].t);
                                
        if(!bellmanFord(0,n,m))
            printf("possible\n");
        else
            printf("not possible\n");
    }
    return 0;
}

