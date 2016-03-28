#include<stdio.h>
#include<time.h>
#include<vector>

using namespace std;

vector<long long > F;

long long  fibonacci(long long n){
    long long a;
    if(n <=2 ) 
        return 1;
    else if(F.size() > n)
        return F[n];         
    else{
        a = fibonacci(n - 1) + fibonacci(n - 2);
        F.push_back(a);       
        return a;
    }
}


long long fibo(double n){
    long i;
    long long proximo,l1=1,l2=0;
    for(i=1; i<=n; i++){
        proximo=l1+l2;
        l1=l2;
        l2=proximo;
    }
    return l2;
}

int main(){
    long long n;
    long m ;
                
    while(scanf("%lld %ld", &n, &m) > 1){
      
        printf("%lld\n",fibonacci(fibonacci(n))%m);
        
    }
    return 0;
}

