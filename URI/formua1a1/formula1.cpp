#include <stdio.h>
#include<iostream>
#include <vector>
/*
P = numero de pilotos <=100
G = numero de corridas <=100
S = quantidade de sistemas de pontuaçao < =10
k = quantifade de posiçoes pontuadas <=P <= 100
*/
using namespace std;

int main(){
    vector<int> v[101];
    vector<int> sPont;
    int p[100];
    int q;
    int maior=1;
    int vc[101];    


    int G, P, S, K, i, j, x;
 
     while((cin >> G >> P)){
         if(G==0 && P == 0)
             return 0;

        for(i=0; i<=P; i++){
            v[i].clear();
        }
         
         for(i=0; i< G; i++){
             for(j=0; j<P; j++){
                 scanf("%d", &x);
                 v[i].push_back(x);
             }
         }


         cin >> S;
                              
         for(i=0; i<S; i++){
            cin >> K;            
                
            sPont.clear();
            
            for(j=0; j<=P; j++){
                p[j]=0;
            }

            for(j=0; j< K; j++){
                cin >> x ;
                sPont.push_back(x);
            }
            
            /*os p cmpetidores estao em ordem v[j][q] é a colocaçao do corredor q no corrida j*/
            for(j=0; j< G; j++){                
                for(q=0; q < P; q++){
                     if(v[j][q] <= K)	
                        p[ q +1] += sPont[ v[j][q] -1 ];
                }
            }
                    
            maior=1;    
            
            for(j=1; j<=P; j++){            
                if(p[maior] < p[j]) maior = j;
            }
            
            q=0;
                                                
            for(j=1; j<=P; j++){
                if(p[maior] == p[j]){
                    vc[q] = j;
                    q++;
                }
            }
                        
            
            for(j=0; j< q; j++){            
                cout << vc[j] ;
                if(j<q-1)
                    cout << " ";            
            }
            cout << endl;                                                         
         }             
     }
     
     return 0;

}
