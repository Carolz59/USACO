#include<bits/stdc++.h>
using namespace std;

long long n,m;
vector<vector<pair<long long,long long>>>adj1,adj2;
vector<long long>dist1,dist2;

void dij(vector<vector<pair<long long,long long>>>&adj,vector<long long>&dist,long long s){
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
                q.push({w+d,newn});
                dist[newn]=w+d;
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    adj1.assign(n+1,vector<pair<long long,long long>>());
    adj2.assign(n+1,vector<pair<long long,long long>>());
    dist1.assign(n+1,LLONG_MAX/2);
    dist2.assign(n+1,LLONG_MAX/2);
    while (m--){
        long long u,v,w;
        cin>>u>>v>>w;
        adj1[u].push_back({w,v});
        adj2[v].push_back({w,u});

    }
    dij(adj1,dist1,1);
    dij(adj2,dist2,n);
    long long g;
    cin>>g;
    long long ans=dist1[n];
    while (g--){
        long long u,v,w;
        cin>>u>>v>>w;
        if(dist1[u]!=LLONG_MAX/2&&dist2[v]!=LLONG_MAX/2){
            ans=min(ans,dist1[u]+w+dist2[v]);
        }
        
    }
    if (ans==LLONG_MAX/2){
        cout<<-1;
  
    }else{
        cout<<ans;
    }
    
    

}
