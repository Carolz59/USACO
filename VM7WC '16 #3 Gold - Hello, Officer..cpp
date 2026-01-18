#include <bits/stdc++.h>
using namespace std;

int n,m,b,q;

vector<vector<pair<int,int>>>adj;
vector<int>dist;


void dij(int s){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

    pq.push({0,s});
    dist[s]=0;

    while (!pq.empty()){
        int node=pq.top().second;
        int weight=pq.top().first;
        pq.pop();

        if (dist[node]<weight){
            continue;
        }

        for (auto u:adj[node]){
            int w=u.first;
            int n=u.second;

            if (dist[n]>w+dist[node]){
                dist[n]=w+dist[node];
                pq.push({dist[n],n});
            }
        }

    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m>>b>>q;

    adj.assign(n+1,vector<pair<int,int>>());
    dist.assign(n+1,INT_MAX);

    for (int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({c,b});
        adj[b].push_back({c,a});
    }

    dij(b);

    for (int i=0;i<q;i++){
        int dest;
        cin>>dest;
        if (dist[dest]==INT_MAX){
            cout<<-1<<endl;
            continue;
        }
        cout<<dist[dest]<<endl;

        
    }
    

}
