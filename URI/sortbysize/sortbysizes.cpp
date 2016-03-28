#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include<set>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(string a, string b){
    return a.size() > b.size();
}

int main(){
    int N, i;
    vector<string> vt;    
    char *p;
    string s;
    char str[51];    
    
    cin >> N;
    getchar();    
    while(N--){
        vt.clear();
    
        fgets(str, 51, stdin);
        /*para nao pegar o /n */
        str[strlen(str)-1] = '\0';
        /*le um substring ate " " e coloca ele no vector, usa um *p pra char mas pode ser atribudo a um tipo string ????*/        
        p = strtok(str," ");        
        for(i=0; p!=NULL;i++){
            s = p;
            vt.push_back(s);
            p = strtok(NULL, " ");
        }

        /*coloco num vector pra poder usar stable_sort que mantem a ordenaçao inicial do vetor*/
        stable_sort(vt.begin(), vt.end(), cmp);
        
        vector<string>::const_iterator itv;
        
        for(itv=vt.begin(); itv != vt.end(); itv++){
            cout << *itv;
            if(itv+1 != vt.end())
                cout<<" "; 
        }
        cout <<endl;
        
    }
    return 0;
}

