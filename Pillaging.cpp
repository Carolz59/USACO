#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,t;
    cin>>n>>t;
    vector<tuple<long long,long long,long long>>v;
    for (int i=0;i<n;i++){
        long long a,b,c;
        cin>>a>>b>>c;
        v.push_back({a,b,c});
    }

    sort(v.begin(),v.end());

    long long l=0;
    long long r=LLONG_MIN/2;
    for (int i=0;i<n;i++){
        auto [p,m,s]=v[i];
        long long newl,newr;
        if (s==0){
            newl=max(l+m,r-t+m);
            newr=max(r,l-t);
        }else{
            newr=max(r+m,l-t+m);
            newl=max(l,r-t);
        }
        l=max(newl,l);
        r=max(newr,r);
        
    }
    cout<<max(l,r);
    

    
    
}
