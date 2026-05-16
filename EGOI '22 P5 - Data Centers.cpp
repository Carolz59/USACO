#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n,m;
    cin>>n>>m;

    vector<long long>v(n);

    for (int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());

    while (m--){
        long long a,b;
        cin>>a>>b;
        for (int i=0;i<b;i++){
            v[i]-=a;
        }

        inplace_merge(v.begin(),v.begin()+b,v.end(),greater<long long>());
    }
    
    for (auto u:v){
        cout<<u<<" ";
    }
    




}
