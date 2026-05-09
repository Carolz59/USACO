#include<bits/stdc++.h>
using namespace std;

//abc
//acb
//bac
//bca
//cab
//cba

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n,a,b,c;
    cin>>n>>a>>b>>c;

    while (b--){
        n=(n+1)/2;
    }
    

    while (a--){
        n=n/2;
    }

    while (c--){
        if (n==0){
            n=0;
            continue;
        }
        n=(n-1)/2;
    }

    
    

    cout<<n;


    
}
