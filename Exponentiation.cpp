#include<bits/stdc++.h>
using namespace std;

long long mod=1e9+7;
long long n;
long long power(long long a,long long b){
    long long ans=1;
    while (b>0){
        if (b%2==1){
            ans=(ans*a)%mod;
        }
        a=a*a%mod;
        b/=2;
    }
    return ans%mod;


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>n;
    while (n--){
        long long a,b;
        cin>>a>>b;
        cout<<power(a,b)<<endl;;
    }
    
}
