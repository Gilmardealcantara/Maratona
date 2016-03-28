#include <bits/stdc++.h>
#define TAM 1001
#define INF 0x3f3f3f3f

using namespace std;

int mat[TAM][TAM]; 
int matAdj[TAM][TAM]; 
long long int d[TAM];
vector< pair<int, int> >g[TAM];


void mostra(int n){

	for(int i=0;i<n*n;i++){
		printf("%d-> ",i);
		for(int j=0;j<g[i].size();j++){
			printf(" %d",g[i][j]);	
		}
		printf("\n");
	}
}

int calcPen(long long  n){
        char s[1000], tmp=0;
        sprintf(s,"%lld", n);
        for(int i=strlen(s)-1; s[i]=='0' && i>=0; i--) tmp++;
        return tmp;
}


bool cmp(int a, int b){
	return d[a] > d[b];
}

void dkt(int s, int n){
	int u, i, vis[TAM];
	vector<int> heap;
	
	heap.clear();
	memset(vis, 0, sizeof(vis));
	memset(d, INF, sizeof(d));

	d[s]=mat[0][0];
	vis[s]=1;
	for(i=0; i<n; i++)
		heap.push_back(i);

	make_heap(heap.begin(), heap.end(), cmp);

	while(!heap.empty()){
		s = heap[0];
		pop_heap(heap.begin(), heap.end(), cmp);
		heap.pop_back();

		for(i=0; i<g[s].size(); i++){
			if(!vis[ g[s][i].first ]){
				if(d[ g[s][i].first ]  > d[s] * g[s][i].second ){
					d[ g[s][i].first ] = d[s] * g[s][i].second;
					vis[ g[s][i].first ]=1;
				}
			}
		}
		make_heap(heap.begin(), heap.end(), cmp);	
	}
		
	
}

void iniGraph(int n){
	for(int i=0; i< n ; i++){
		for(int j=0; j<n; j++){
			matAdj[i][j]=INF;
		}
		matAdj[i][i]=0;
	}
}

void fw(int n){
	for(int k=0; k<n; k++){
		for(int i=0; i< n ; i++){
			for(int j=0; j<n; j++){
				matAdj[i][j]=min(matAdj[i][j], calcPen( matAdj[i][k]+matAdj[k][j]) );	
			}
		}
	}	
	
}

void mostraMat(int n){
	for(int i=0; i<n*n; i++){
		for(int j=0; j<n*n; j++){
			printf("%d ", matAdj[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
int main(){
	int n,i,j,x;

	
	while( scanf("%d", &n)==1 && n){
		
		map< pair<int,int>, int >mp;
		x=0;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				scanf("%d",&mat[i][j]);
				mp[make_pair(i,j)]=x++;
			}
		}

		iniGraph(n*n);
		mostraMat(n);
		
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
			
				if(j<n-1 && mat[i][j+1]!=0 ){	
					g[ mp[make_pair(i,j) ] ].push_back(make_pair(mp[make_pair(i,j+1)], mat[i][j+1]));
					matAdj[ mp[make_pair(i,j)] ][ mp[make_pair(i,j+1)] ] = mat[i][j+1];				
				}
				if(i<n-1 && mat[i+1][j]!=0 )
					g[ mp[make_pair(i,j) ] ].push_back(make_pair(mp[make_pair(i+1,j)], mat[i+1][j]));
					matAdj[ mp[make_pair(i,j)] ][ mp[make_pair(i+1,j)] ] = mat[i+1][j];
			}
			
		}		
//		dkt(0, n*n);
		mostraMat(n);	
		fw(n*n);	
		mostraMat(n);		
		//printf("\n%d\n", d[n*n-1]);
		//mostra(n);
	}
	return 0;
}
