#include<stdio.h>
#include<vector>
#include<string.h>

using namespace std;


vector<int> g[55];
int vis[55];
int num[55];


void dfs(int s){
	vis[s]=1;
	for(int i=0; i<(int)g[s].size(); i++){
		if(!vis[g[s][i]]){
			num[s]++;
			dfs(g[s][i]);
		}
	}
}

void mostraVis(int n){
	for(int i=1; i<=n; i++){
		printf("%d-(%d)  ", i, num[i]);
	}
	printf("\n");

}

int main(){
	int c, p, x, y;
	
	while(scanf("%d %d", &c, &p)>=2){
		memset(vis, 0, sizeof(vis));
		memset(num, 0, sizeof(num));
		for(int i=0; i<=c; ++i)
			g[i].clear();

		while(p--){
			scanf("%d %d", &x, &y);
			g[x].push_back(y);
			g[y].push_back(x);
		}
		
		for(int i=1;i<=c; i++){
			if(!vis[i])
				dfs(i);
		}
		mostraVis(c);
	}

	return 0;
}
