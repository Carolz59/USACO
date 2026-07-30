#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    vector<int>psa(n+1),a(n);
    while (k--){
        long long p;
        cin>>p;
        a[p]++;

    }
    for (int i=1;i<=n;i++){
        psa[i]=psa[i-1]+a[i-1];
    }
    int q;
    cin>>q;
    while (q--){
        int a,b;
        cin>>a>>b;
        cout<<psa[b+1]-psa[a]<<endl;;
    }

}
