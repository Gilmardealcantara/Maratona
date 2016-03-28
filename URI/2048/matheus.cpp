#include<stdio.h>
#include<stdlib.h>

int matriz [4][4];
int aux[4];
int i, j;

int desce();
int sobe();
int esq();
int dir();
int verifica();

int main(){


	int casos;
	
	scanf("%d", &casos);
	
	while(casos>0){
		
		for(i=0; i<4; i++)
			for(j=0; j<4; j++)
				scanf("%d", &matriz[i][j]);
		
		if(verifica()){
			aux[0]=sobe();//down
			aux[1]=esq();//left
			aux[2]=dir();//right
			aux[3]=desce();//up
		
			if(aux[0]==1)
				printf("DOWN");
			if(aux[1]==1)
				if(aux[0]==1)
					printf(" LEFT");
				else
					printf("LEFT");
			if(aux[2]==1)
				if(aux[0]==1 || aux[1]==1)
					printf(" RIGHT");
				else
					printf("RIGHT");
			if(aux[3]==1)
				if(aux[0]==1 || aux[1]==1 || aux[2]==1)
					printf(" UP");
				else
					printf("UP");
		
			for(i=0; i<4; i++)
				if(aux[i]==1)
					break;
			if(i==4)
				printf("NONE");	
		}
		else		
			printf("NONE");					
	
		printf("\n");
		casos--;
	}
	
	return 0;

}

int verifica(){

	for(i=0; i<4; i++)
		for(j=0; j<4; j++)
			if(matriz[i][j]==2048)
				return 0;

	return 1;
}

int sobe(){
	
	for(j=0; j<4; j++){
		for(i=0; i<3; i++){			
				if(matriz[i][j]!=0)
					if(matriz[i+1][j]==0  || matriz[i+1][j]==matriz[i][j] )				
						return 1;
							
			}
	}
	 return 0;
}

int desce(){
	
	for(j=0; j<4; j++){
		for(i=3; i>0; i--){			
				if(matriz[i][j]!=0)				
					if(matriz[i-1][j]==0  || matriz[i-1][j]==matriz[i][j] )				
						return 1;
							
			}
	}
	 return 0;
}

int esq(){
	
	for(i=0; i<4; i++){
			for(j=3; j>0; j--){
				if(matriz[i][j]!=0)
					if(matriz[i][j-1]==0  || matriz[i][j-1]==matriz[i][j] )				
						return 1;
							
			}
	}
	 return 0;
}

int dir(){
	
	for(i=0; i<4; i++){
			for(j=0; j<3; j++){
				if(matriz[i][j]!=0)
					if(matriz[i][j+1]==0  || matriz[i][j+1]==matriz[i][j] )				
						return 1;
							
			}
	}
	 return 0;
}
