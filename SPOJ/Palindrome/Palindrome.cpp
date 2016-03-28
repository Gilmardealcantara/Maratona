#include<bits/stdc++.h>

using namespace std;

set<string> st;

int palindrome(string s){
		int i, j;
		if(s.size()==1)
			return 0;	
		for(i=0, j=(s.size()-1); i<=j; i++, j--){
			if(s[i]!=s[j])
				return 0;
		}
		return 1;
}

void f(string s){
	string tmp;
	for(int i=0; i<s.size(); i++){
		for(int tam=1; (tam+i)<=s.size(); tam++){
			tmp = s.substr(i, tam);
			if(palindrome(tmp)){
				st.insert(tmp);
				cout << tmp<<endl;
			}
		}
	}
	cout <<endl;
}


int main(){
	string s;
	int n=1, t=1;

	while(1){
		cin >> n;
		//cout << "aq \n"<<n<<endl;
		if(n==0)
			break;
		st.clear();
		cin >> s;	
		f(s);	
	
		set<string>::iterator i;

		for(i = st.begin(); i != st.end(); i++){
			cout << *i<<endl;
		}

		printf("Teste %d \n%d\n\n",t++,st.size());
	}
	return 0;
}
