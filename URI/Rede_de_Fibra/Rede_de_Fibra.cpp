#include<bits/stdc++.h>

using namespace std;

struct no{
	int u;
	string emp;
};

vector<no> g[201];
int vis[201];

string getInter(string a, string b){
	string g;
	for(int i=0; i<a.size(); i++){
		for(int j=0; j<b.size(); j++){
			if(a[i]==b[j]){
				g+=a[i];
			}
		}
	}
	return g;
}

void dfs(int u){
	vis[u]=1;
	for(int i=0; i<g[u].size(); i++){
		if(!vis[ g[u][i].u ]){
			dfs( g[u][i].u );
		}
	}
}

void bfs(int u, int v){
	queue<int> l;
	int s;
	l.push(u);
	vis[u]=1;
	
	while(!l.empty()){
		s=l.front();
		l.pop();
		for(int i=0; i<g[s].size(); i++){
			if(!vis[ g[s][i].u ]){
				vis[ g[s][i].u ]=1;
				l.push( g[s][i].u );
			}
		}
		//vis[s]=2;	
	}	

}

void mostraVis(int n){
	for(int i=1; i<=n; i++)
		printf("%d ", vis[i]);
	printf("\n");
}

int main(){
	
	int v, u, i, n;
	string s;
	no aux;

	while(scanf(" %d", &n)){
		if(n==0) break;

		v=1; u=1;
		while(1){
			cin >> u >> v;
			if(u==0 && v==0) break;
			cin  >> s;
			//printf("%d %d\n", u, v);
			aux.u=v;
			aux.emp=s;
			g[u].push_back(aux);
		}
		u=1; v=1;
		
		while(1){	
			cin >> u >> v;
			if(u==0 && v==0) break;
			for(i=1; i<=n; i++)
				vis[i]=0;
			//printf("%d %d\n", u, v);
			//dfs(u);
			bfs(u,v);
			mostraVis(n);
		}	
	}










	/*string a="abc";
	string c="ad";
	string g = getInter(a,c);

	cout << g<<endl;		
	*/
	return 0;
}
