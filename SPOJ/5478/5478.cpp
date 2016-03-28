#include<stdio.h>

int main(){
	int B, N, i, j;
	int r[21], bd[21][3];
		
	while(scanf("%d %d", &B, &N) > 1){
		if(B==0 && N==0)
			return 0;

		for(i=1; i<=B; i++)
			scanf("%d ", &r[i] );

		for(i=1; i<=N; i++){
			for(j=0; j<3; j++){
				scanf("%d ", &bd[i][j]);
			}
		}
		
		int flag=0;

		for(i=1; i<=N; i++ ){
			//se valor da reserva  e >=  q  devedor(D) deve
			int D = bd[i][0], C = bd[i][1], V=bd[i][2];
			
			//printf("%d %d %d\n", D, C, V);
			
			if(r[D]>=V){
				r[D] = 0;
				r[C] += V;
				V=0;
			}else if(r[D] > 0){
				V-=r[D];
				r[C] += r[D];
				r[D] = 0;  
			}

			bd[i][2] = V; //atualiza valor 
			if(i==N && flag==0){
				i=0;
				flag=1;
			}
		}
		
				
		for(i=1; i<=N; i++){
			if(bd[i][2] > 0) flag=0;		
		}
		
		if(flag)
			printf("S\n");
		else
			printf("N\n");
					

	}	

	return 0;
}




