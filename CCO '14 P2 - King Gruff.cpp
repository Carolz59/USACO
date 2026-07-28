#include<bits/stdc++.h>
using namespace std;

long long n,m,a,b;
vector<vector<pair<long long,long long>>>adj1,adj2;
vector<long long>dist1,dist2;

void dij(long long s,vector<vector<pair<long long,long long>>>&adj,vector<long long>&dist){
    dist[s]=0;
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>q;
    q.push({0,s});

    while (!q.empty()){
        auto [d,node]=q.top();
        q.pop();
        if (d>dist[node]){
            continue;
        }
        for (auto [w,newn]:adj[node]){
            if (w+d<dist[newn]){
                dist[newn]=w+d;
                q.push({w+d,newn});
            }
        }
    }
    return;

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>a>>b;
    adj1.assign(n+1,vector<pair<long long,long long>>());
    adj2.assign(n+1,vector<pair<long long,long long>>());
    dist1.assign(n+1,LLONG_MAX/2);
    dist2.assign(n+1,LLONG_MAX/2);
    vector<tuple<long long,long long,long long,long long>>cost;
    while (m--){
        long long x,y,l,c;
        cin>>x>>y>>l>>c;
        cost.push_back({x,y,l,c});

        adj1[x].push_back({l,y});
        adj2[y].push_back({l,x});

    }

    dij(a,adj1,dist1);
    dij(b,adj2,dist2);
    long long q;
    cin>>q;
    vector<long long>v(q),ans(q);
    for (int i=0;i<q;i++){
        cin>>v[i];

    }
    vector<pair<long long,long long>>need;
    
    for (auto [f,s,l,c]:cost){
        if (dist1[f]<LLONG_MAX/2&&dist2[s]<LLONG_MAX/2){
            need.push_back({dist1[f]+l+dist2[s],c});
        }
        
    }
    sort(need.begin(),need.end());
    vector<long long>psa(need.size()+1);
    for (int i=0;i<need.size();i++){
        psa[i+1]=psa[i]+need[i].second;
    }
    for (auto p:v){
        auto it=upper_bound(need.begin(),need.end(),make_pair(p,LLONG_MAX));
        cout<<psa[it-need.begin()]<<endl;
    }


    
    

    

    
}
