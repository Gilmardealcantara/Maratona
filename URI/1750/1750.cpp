#include<stdio.h>
#include<algorithm>
#include<math.h>

using namespace std;

int n, v[1005];
int vsolus1=0, vsolusn=0;

void mostra(int n){
	for(int i=0; i<n; i++){
		printf("%d ",v[i]);
	}printf("\n");
}

int dist(int i, int j){
	return  min( (abs(v[i]-v[j])),24 - (abs(v[i]-v[j])));
}


int pars1(int s, int n){
	int e=s+1, mini=dist(s,s+1);
	
	for(int i=s+2; i<n; i++){
		if(mini > dist(s,i) ){ 
			e=i;
			mini=dist(s,i);
		}
	}
	return e;
}


void acha_caras1(){
	int i;
	vsolus1=0;
	for(i=0; i<n; i+=2){
		int j=pars1(i, n);
		int aux=v[i+1];
		v[i+1]=v[j];
		v[j]=aux;

		vsolus1+=dist(i,i+1);
	}	
}


void acha_carasn(){
	int i, j;
	vsolusn=0;
	for(i=0, j=n; i<n; i+=2, j-=2){
		int j=pars1(i, n);
		int aux=v[i+j];
		v[i+j]=v[j];
		v[j]=aux;

		vsolusn+=dist(i,i+j);
	}	
}



int main(){
	
	int vlei[1005];
	scanf("%d ", &n);

	for(int i=0; i<n ; i++){
		scanf("%d ", &vlei[i]);
		v[i]=vlei[i];
	}
	acha_caras1();

	for(int i=0; i<n ; i++)
		v[i]=vlei[i];

	acha_carasn();
	
	if(vsolus1<vsolusn)
		printf("%d\n", vsolus1);
	else
		printf("%d\n", vsolusn);

	return 0;
}
