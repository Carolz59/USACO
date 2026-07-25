#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>>adj;
vector<bool>vis;


void dfs(int s,int ban1,int ban2){
    if (vis[s]){
        return;
    }
    vis[s]=true;
    for (auto u:adj[s]){
        if (s==ban1&&u==ban2){
            continue;
        }
        dfs(u,ban1,ban2);
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    adj.assign(n+1,vector<int>());
    vector<pair<int,int>>p;
    while (m--){
        int u,v;
        cin>>u>>v;
        p.push_back({u,v});
        adj[u].push_back(v);
    }
    for (auto [u,v]:p){
        vis.assign(n+1,false);
        dfs(1,u,v);
        if (!vis[n]){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
        
    }

}
 
