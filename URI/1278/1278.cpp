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
			int i, j;
			string boa;
			for(i=0; i<str.size(); i++){
				j=i;
				string s;
				while(str[i] != ' '&& i<str.size()) i++;
				
				s = str.substr(j,i-j);
				
				if(s !="")
					boa+=s+' ';

			}
			boa.erase(boa.begin() + boa.size()-1);
			
			if(max_tam < boa.size()) max_tam = boa.size();

			text.push_back(boa);
		}

		for(int i=0; i<text.size(); i++){
			int num_esp = max_tam - text[i].size();

			while(num_esp--){ cout <<" "; }
			cout << text[i]<<endl;
		} 	
		cout << endl;
	}
	
	return 0;
}
