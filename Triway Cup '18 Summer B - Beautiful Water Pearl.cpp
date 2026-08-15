#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long a,b,c;
    cin>>a>>b>>c;
    if (b+c!=a){
        cout<<0<<endl;
        return 0;
    }
    long long ans=1;
    while (c>0){
        if ((c&1)){
            ans*=2;  

        }
        c>>=1;
    }
    cout<<ans<<endl;
}
