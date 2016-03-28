#include<bits/stdc++.h>


using namespace std;

void mostra(queue<int> p){
	printf("Discarded cards: ");
	for(int i=0; !p.empty(); i++){
		printf("%d",p.front());
		if(p.size()>1)
			printf(", ");
		p.pop();	
	}
	printf("\n");
}

int main(){
	queue<int> p;
	queue<int> f;
	int n=1, i;
	
	while(scanf(" %d", &n)){
		if(n==0)
			break;	
		for(i=1; i<=n; i++)
			p.push(i);
		while(p.size()>1){
			f.push(p.front());
			p.pop();
			p.push(p.front());
			p.pop();
		}
		
		mostra(f);
		printf("Remaining card: %d\n", p.front());
		p.pop();	
		while(!f.empty())
			f.pop();
	}

	
	return 0;
}
