#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n,k;
    cin>>n>>k;
    vector<pair<long long,long long>>v(n);

    for (int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(),v.end());
    long long ans=0;
    priority_queue<long long,vector<long long>,greater<long long>>q;
    for (int i=n-1;i>=0;i--){
        q.push(v[i].second);

        if (q.size()>k){
            q.pop();
        }
        if (q.size()==k){
            ans=max(ans,v[i].first*q.top());
        }
        

    }

    cout<<ans;




}
