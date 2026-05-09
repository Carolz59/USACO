#include<bits/stdc++.h>
using namespace std;

int n,k;
vector<bool>imp;
vector<vector<pair<int,int>>>adj;
vector<int>vis;

bool prune(int u,int p){
    for (auto [wei,v]:adj[u]){
        if (v==p){
            continue;
        }
        if (prune(v,u)){
            imp[u]=true;
        }
    }
    return imp[u];
}

int tot=0;
int dfs(int s){
    vis[s]=true;
    for (auto [wei,nod]:adj[s]){
        if (!vis[nod]&&imp[nod]){
            tot+=wei;
            dfs(nod);
        }
    }
    return tot;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    adj.assign(n+1,vector<pair<int,int>>());
    imp.assign(n+1,false);
    vis.assign(n+1,false);
    imp[1]=true;

    for (int i=0;i<n-1;i++){
        int u,v,w;
        cin>>u>>v>>w;

        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }

    for (int i=0;i<k;i++){
        int x;
        cin>>x;
        imp[x]=true;
    }

    prune(1,0);
    cout<<dfs(1);


    
}
