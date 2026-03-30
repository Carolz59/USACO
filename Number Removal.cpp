#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n,k;
    cin>>n>>k;
    long long len=n;
    long long steps=0;

    while (len>=k){
        steps++;
        if (n%k==0){
            cout<<steps;
            return 0;
        }
        n-=n/k;
        len-=len/k;
        
        
    }

    cout<<0;


}
