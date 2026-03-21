#include<bits/stdc++.h>
using namespace std;

int n,m,k;
vector<vector<int>>adj;
vector<int>val,dp;
vector<int>dist;

void bfs(){
    dist.assign(n+1,INT_MAX);
    queue<int>q;
    for (int i=1;i<=n;i++){
        if (dp[i]!=INT_MAX){
            dist[i]=dp[i];
            q.push(i);
        }
    }

    while (!q.empty()){
        int cur=q.front();
        q.pop();
        
        for (auto u:adj[cur]){
            if (dist[u]>dist[cur]+1){
                dist[u]=dist[cur]+1;
                q.push(u);
            }
        }
    }
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m>>k;
    adj.assign(n+1,vector<int>());
    val.assign(n+1,0);
    dp.assign(n+1,INT_MAX);
    for (int i=1;i<=n;i++){
        cin>>val[i];
        if (val[i]==0){
            dp[i]=0;
        }
    }

    for (int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs();
    vector<int>newdp(n+1,INT_MAX);

    for (int i=1;i<=n;i++){
        if (dist[i]!=INT_MAX&&val[i]==1){
            newdp[i]=dist[i];

        }
        
    }
    dp=newdp;

    for (int i=2;i<=k;i++){
        bfs();
        vector<int>nd(n+1,INT_MAX);
        for (int j=1;j<=n;j++){
            if (dist[j]!=INT_MAX&&val[j]==i){
            nd[j]=dist[j];

        }
        }
        dp=nd;

    }
    int ans=INT_MAX;
    for (int i=1;i<=n;i++){
        if (val[i]==k){
            ans=min(dp[i],ans);
        }
    }
    cout<<ans;


    
}
