#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

int main(){
	char str1[501];
	char str2[501];
	int num;
	int i, j;	

	while(gets(str1)){
		if(str1 == "\n"){
		    cout << "error_str1_vazia\n";
		    continue;
		}

		for(i=0, j=0; str1[i] != '\0'; i++){
		    if(str1[i] == '.'){
		        str2[0] ='\0';
		        cout << "._";
		        break;
        }
	    
			if(str1[i] == ' ' || str1[i] == ',' )
			    continue;
		    
			if(str1[i] == 'O' || str1[i] == 'o')
				str1[i] = '0';
				
			if(str1[i] == 'l')
				str1[i] ='1';
				
			if(str1[i] >= '0' && str1[i] <= '9'){
				str2[j] = str1[i];
				j++;
			}else{
			    str2[0] ='\0';
			    cout << "letra_";
		        break;
			}
			
		}

		str2[j] = '\0';
		
		if(str2[0] == '\0'){
		    cout << "error_str2_vazia\n";
		    continue;
		}
		
		for(i=0; str2[i]=='0'; i++) j--;
		
	    if(j>10){
	        cout << "error_+10alg\n";
	        continue;
		}

		if(j == 10 && str2[0] > '2'){
		    cout << "error_10_p>2\n";
	        continue;
		}
		    
	    num = atoi(str2);
	   
		if(num < 0 || num >  2147483647){
		    cout << "error_>2147483647\n";
            continue;
		}	
		
		cout << num <<endl;			
			
	}

	return 0;
}
