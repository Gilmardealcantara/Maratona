#include<stdio.h>
//tendo como base o angulo no ponteiro de 12 horas
int main(){
	int h, m, deslocamentoPH,anguloH,anguloM, angulo;	
	printf("\nCalculo do angulo dos ponteiros de um relogio  !!!\n\n");
	printf("Insira as horas: \t");
	scanf(" %d",&h);
	printf("Insira os Minutos: \t");	
	scanf(" %d",&m);
	deslocamentoPH = 30*m/60; //regra de 3 com os minutos 
	anguloH= h*30 + deslocamentoPH;
	anguloM=m*6;
	angulo=anguloH-anguloM; 
	printf("\nO angulo entre os ponteiros e de %d graus \n\n", angulo);
}
