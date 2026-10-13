#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cin>>n;
    vector<pair<long long,int>>v;
    vector<long long>c;
    for (int i=0;i<n;i++){
        long long a,b;
        cin>>a>>b;
        v.push_back({a,1});
        v.push_back({b,-1});
        c.push_back(a);
        c.push_back(b);
    }

    sort(c.begin(),c.end());
    c.erase(unique(c.begin(),c.end()),c.end());

    for (long long i=0;i<2*n;i++){
        long long comp=lower_bound(c.begin(),c.end(),v[i].first)-c.begin();
        v[i].first=comp;

    }
    sort(v.begin(),v.end());
    long long cur=0;
    long long best=0;
    for (long long i=0;i<2*n;i++){
        auto [x,y]=v[i];
        cur+=y;
        best=max(cur,best);


    }
    cout<<best;





    
    
}
