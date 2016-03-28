#include<bits/stdc++.h>
#define INF 0xf3f3f3f
using namespace std;
int n, p=INF;
long long m[1006][1006];

void calcPen(long long  n){
	char s[1000], tmp=0;	
	sprintf(s,"%lld", n);
	for(int i=strlen(s)-1; s[i]=='0' && i>=0; i--) tmp++;
	if(tmp<p)
		p=tmp;	
}

void testa(int i, int j, long long c){
	if(i==(n-1) && j==(n-1)){
		c*=m[i][j];
		calcPen(c);
		printf("%d\n", c);
		return;
	}

	c*=m[i][j];
	if(i<(n-1))
		if(m[i+1][j]!=0)
			testa(i+1, j,c);
	if(j<(n-1))
		if(m[i][j+1]!=0)
			testa(i, j+1, c);	
			
}

int main(){

	scanf("%d", &n);
	long long c=1;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf(" %lld", &m[i][j]);
		}
	}

	testa(0,0, c);
	printf("%d\n", p);
	return 0;
}
