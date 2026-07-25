#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin>>n;

    long long ans=0;

    for(long long two=1;two*2<=n;two++){
        long long one=n-2*two;
        ans=max(ans,two*one*(one-1)/2);
    }

    cout<<ans;
}
 
