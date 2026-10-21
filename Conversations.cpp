#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,m;
    cin>>n>>m;
    vector<pair<long long,long long>>v;

    for (int i=0;i<n;i++){
        long long x,y;
        cin>>x>>y;

        v.push_back({x,y});
    }

    sort(v.begin(),v.end());
    long long ans=v[0].second;
    for (int i=1;i<n;i++){
        if (v[i].second>v[i-1].second){
            ans+=v[i].second-v[i-1].second;
        }
        
    }
    cout<<ans;


    

    
    
}
