#include<stdio.h>

int main(){
int a, b, i=1, j=1;

for(a=-1; a<=1; a++)
	for(b=-1; b<=1; b++)
		printf("%d% d\n", i+a, j+b); //mat[i+a] [j+a] > mar[i][j]


}
/*
i+1, j+1
i-1, j-1
i+1,j-1
i-1,j+1
i+1, j
i-1, j
i, j+1
i, j-1
*/
