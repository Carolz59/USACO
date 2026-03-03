#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<pair<int,int>>>adj;//adj[u]={w,v}
vector<vector<int>>dist; //dist[stage][node]=dist
vector<int>type;

int dij(int s){
    dist.assign(5,vector<int>(n+1,INT_MAX));
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>q;
    if (type[s]==1){
        q.push({0,1,s});
    }else{
        q.push({0,0,s});
    }
    
    dist[0][s]=0;

    while (!q.empty()){
        auto [dis,typ,node]=q.top();
        q.pop();
        if (dis>dist[typ][node]){
            continue;
        }
        for (auto [w,v]:adj[node]){
            int newt=typ;

            if (typ<4&&type[v]==typ+1){
                newt++;
            }

            if (w+dis<dist[newt][v]){
                dist[newt][v]=w+dis;
                q.push({w+dis,newt,v});
            }
        }
        
    }
    int ans=INT_MAX;

    for (int i=1;i<=n;i++){
        ans=min(ans,dist[4][i]);
    }
    return ans;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    adj.assign(n+1,vector<pair<int,int>>());
    type.assign(n+1,-1);
    

    for (int i=1;i<=n;i++){
        cin>>type[i];
    }

    for (int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});

    }

    int ans=dij(1);

    if (ans==INT_MAX){
        cout<<-1;
    }else{
        cout<<ans;
    }




    
}
