#include <stdio.h>
#include <string>
#include <iostream>
#define DIM 4

using namespace std;
int main(){
    int t, i, j, e=0;
    int mat[DIM+2][DIM+2];
    string d="",l="",r="",u="";
    string s[4];
    string str[5];
    
    
    scanf("%d", &t);
    
    while(t--){
        d="";l="";r="";u=""; e=0;
        
        for(i=0; i<DIM+2; i++){
            for(j=0; j<DIM+2; j++){
                if(j==0 || i==0 || i==(DIM+1) || j == (DIM+1))
                    mat[i][j] = 1;
                else    
                    scanf("%d", &mat[i][j]);
                
            }
        }
        
            
        for(i=1; i<=DIM; i++){
            for(j=1; j<=DIM; j++){
                if(mat[i][j] == 2048){
                    d="";l="";r="";u="";
                    e=1;
                    break;
                }
                
                if(mat[i][j] != 0 && (mat[i-1][j] == 0 || mat[i-1][j] == mat[i][j]))
                   u="UP";   
                if(mat[i][j] != 0 && (mat[i+1][j] == 0 || mat[i+1][j] == mat[i][j]))
                   d="DOWN";   
                if(mat[i][j] !=0 && (mat[i][j-1] == 0 || mat[i][j-1] == mat[i][j]))
                   l="LEFT";
                if(mat[i][j] !=0 && (mat[i][j+1] == 0 || mat[i][j+1] == mat[i][j]))
                   r="RIGHT";
          }
            if(e){
                e=0;
                break;
            } 
        }
        
        s[0] = d;
        s[1] = l;
        s[2] = r;
        s[3] = u;
        if(d=="" && l=="" && r=="" && u== "")    
            cout <<"NONE"<<endl;
        else{
        
            for(i=0, j=0; i<4; i++){
                if(s[i]!=""){
                    str[j]=s[i];
                    j++;
                    str[j]="";
                }
            }
            for(i=0; str[i] != ""; i++){
                    cout << str[i];
                    if(str[i+1] != "")
                        cout<<" ";    
                }
            cout<<endl;            
        }
    }
    return 0;
}




/*
void mostra(int m[DIM+2][DIM+2]){
    int i, j;
    for(i=0; i<DIM+2; i++){
        for(j=0; j<DIM+2; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
*/

