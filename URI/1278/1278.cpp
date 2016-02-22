#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>

using namespace std;

int main(){
	int N;
	int flag, max_tam=0, flag2=0;
	string str, str_out;
	vector<string> text;

	while(scanf("%d ", &N), N){
		if(flag2)
			printf("\n");
		else
			flag2=1;

		max_tam=0;
		str_out="";
		text.clear();
		while(N--){	
				getline(cin, str);
				flag=0;
				str_out="";	

				for(int i=0; i<str.size() && str[i]!= '\n'; i++){
				
					while(str[i]==' ' && str[i+1]==' ' ) i++;
					
					if(str[i] == '\n') break;

					if(str[i]==' ' && flag==0) i++;

					str_out+=str[i];
					flag=1;				
				}

				text.push_back(str_out);

				if(max_tam < str_out.size()) max_tam = str_out.size();
		}

		for(int i=0; i<text.size(); i++){
			int num_esp = max_tam - text[i].size();
			string str_out2;
			while(num_esp--){
				str_out2+=' ';
			}
			str_out2+= text[i]; 
			cout << str_out2 << endl;
		}
	}
	
	return 0;
}
