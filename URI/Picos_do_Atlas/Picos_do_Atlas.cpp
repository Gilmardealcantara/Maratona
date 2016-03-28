#include<stdio.h>
#include<vector>
#include<algorithm>
#define INF 0x3f3f3f3f

using namespace std;

bool cmp1(pair<int, int> a, pair<int, int> b){
	return a.first < b.first;
}

bool cmp2(pair<int, int> a, pair<int, int> b){
	return a.second < b.second;
}

int main(){
	int M, N, i, j, flag, a, b;
	int map[1050][1050];
	vector<pair<int, int> > lista;
    
	while(scanf("%d %d", &N, &M) > 0){
	
		lista.clear();
		for(i=0; i<=N+1; i++){
			map[i][0]=-INF;
			map[i][M+1]=-INF;
		}
		for(i=0; i<=M+1; i++){
			map[0][i]=-INF;
			map[N+1][i]=-INF;
		}

		for(i=1; i<=N; i++){
			for(j=1; j<=M; j++){
				scanf(" %d", &map[i][j]);
			}
		}
	

		for(i=1; i<=N; i++){
			for(j=1; j<=M; j++){
				flag=0;
				//printf("%d ", map[i][j]);		
				for(a=-1; a<=1; a++){
					for(b=-1; b<=1; b++){
						
						if(map[i+a][j+b] < map[i][j]){
							flag++; //nao e i maior 
						}
					}
				}
			
				if(flag==8){
					lista.push_back(make_pair(i,j));
					//printf("%d %d\n", i, j, map[i]);
				}
			}//printf("\n");
		}

		if(!lista.empty()){
			sort(lista.begin(), lista.end(), cmp2);	
			stable_sort(lista.begin(), lista.end(), cmp1);

			for(i=0; i<lista.size(); i++){
				printf("%d %d\n", lista[i].first, lista[i].second);
			}
	
		}else{
			printf("-1\n");
		}
		printf("\n");
	}
	return 0;
}
