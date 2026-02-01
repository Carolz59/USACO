#include <bits/stdc++.h>
using namespace std;

long long n,m;
vector<vector<pair<long long,long long>>>adj;
vector<long long>dist;

long long dij(long long s,long long f){
    dist.assign(n+1,LLONG_MAX);
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>q;
    dist[s]=0;
    q.push({0,s});

    while (!q.empty()){
        auto [l,node]=q.top();
        q.pop();

        if (l>dist[node]){
            continue;
        }

        if (node==f){
            return l;
        }

        for (auto [w,newn]:adj[node]){
            if (dist[node]+w<dist[newn]){
                dist[newn]=dist[node]+w;
                q.push({dist[newn],newn});
            }
        }
    }
    return LLONG_MAX;

}

int main(){
    cin>>n>>m;
    adj.assign(n+1,vector<pair<long long,long long>>());
    
    priority_queue<tuple<long long,long long,long long,long long>,vector<tuple<long long,long long,long long,long long>>,greater<tuple<long long,long long,long long,long long>>>pq;
    
    for (int i=0;i<m;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if (a>b){
            swap(a,b);
        }
        pq.push({c,d,a,b});

    }

    long long ans=0;
    
    while (!pq.empty()){
        auto [len,cos,u,v]=pq.top();
        pq.pop();

        long long d=dij(u,v);
        

        if (d>len){
            ans+=cos;
            adj[u].push_back({len,v});
            adj[v].push_back({len,u});
        }

    }

    cout<<ans;
    
    
    
    
}
