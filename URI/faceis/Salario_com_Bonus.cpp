#include<stdio.h>
#include<string>
#include <iostream>

using namespace std;

int main(){
	double S, M;
	string str;
	
	cin >> str;
	scanf("%lf %lf ", &S, &M);
	getchar();
	printf("TOTAL = R$ %.2lf\n", S + (M*0.15));		

	return 0;
}
