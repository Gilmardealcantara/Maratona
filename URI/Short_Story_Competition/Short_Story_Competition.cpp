/*
 N (2 ≤ N ≤ 1000) : palavras;
 L (1 ≤ L ≤ 30 )  : linhas por página   
 C (1 ≤ C ≤ 70)  : caracteres por linha    
*/

#include<stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main(){
    int N, L, C, i, j, linha, cOrig;
    string str;
    float tmp;
    int p;
    
    while(scanf("%d %d %d", &N, &L, &C) >=0){
        getchar();
        linha=0;
        cOrig=C;
        getline(cin, str);
        //cout << str<<endl<<endl;
        
        for(i=0; i<str.size(); i++){
                    
            if(i==(C-1)){ /*linha completa*/
                for(j=0; str[i]!=' '; i--)j++;
                i++;//espaço a mais
                
                C+=cOrig+j;/*para poder contar outra linha*/
                linha++;
            //    cout << "\n";
            }
            
            //cout <<str[i];
         //   if((i) >= str.size() && i!=(C-1))
        //        linha++;            
        }
        
        //if(i<C)
        //    linha++;
        tmp=(float)linha/(float)L;
        p=linha/L;
        
        if(tmp <= linha/L)
            p=linha/L+1;    
         printf("%d  %d  %f\n", linha/L, p, tmp);
                     
         //cout <<"\n\nlinhas: "<< linha << "\npagfloat: "<< pag <<"\n";   
        //cout  <<"\n\n paginas int: "<< p <<" linhas: "<< linha << " paginasfloat: "<< pag <<endl;/*numero de paginas e a qlinhas/qde linas por pagina*/    

        
        
    }
    
    return 0;
}





        //printf("%d %d %d\n", N, L, C);            
        //gets(str);
        //printf("%s\n", str);     
        
