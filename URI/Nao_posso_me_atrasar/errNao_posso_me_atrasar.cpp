#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
 
 
using namespace std;
 
int M[55][55];
 
 
void fw(int n){
 
    for(int k=0; k<n; k++){
        for(int j=0; j<n; j++){
            for(int i=0; i<n; i++){
                M[i][j] = min(M[i][j], M[i][k]+ M[k][j]);
            }
        }   
    }
}
 
 
void print(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
 
int main(){
    int X, N, V, T;
    string O, D;
 
    map<string, int> mapa;
 
     
    while(scanf("%d %d %d", &X, &N, &V), X+N+V){
        int naux=N;//quantidade de rotas 
        int i=0;
        memset(M, INF, sizeof(M));  
        for(int i=0; i<V; i++) M[i][i]=0;
         
        while(naux--){
            cin >> O >> D >> T;
 
            if(mapa.count(O) <= 0)
                mapa[O]=i++;
            if(mapa.count(D) <= 0)
                mapa[D]=i++;
 
            M[ mapa[O] ][ mapa[D] ] = T;
        }
    //  print(V);       
        fw(V);
    //  print(V);       
 
        int tmg=M[ mapa["varzea"] ][ mapa["alto"] ];
        int mi=30;
        if(X>30)
            mi=50;
        tmg+=mi;
 
        //17
        int h=17+tmg/60, m=tmg%60;
        if(h>18){
			if(m>9)
            	printf("%d:%d\nIra se atrasar\n", h, m);
			else	
            	printf("%d:0%d\nIra se atrasar\n", h, m);
        }else if(h==18 && m>0){
			if(m>9)
            	printf("%d:%d\nIra se atrasar\n", h, m);
        	else
            	printf("%d:0%d\nIra se atrasar\n", h, m);
		}else{ 	
			if(m>9)
				printf("%d:%d\nNao ira se atrasar\n", h, m);
			else
				printf("%d:0%d\nNao ira se atrasar\n", h, m);
		}         
    }
     
    return 0;
}
