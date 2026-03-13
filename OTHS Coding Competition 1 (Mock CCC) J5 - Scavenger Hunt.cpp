#include<bits/stdc++.h>
using namespace std;

int n,m,k;

vector<vector<pair<long long,int>>>adj;
vector<long long>dp;
vector<long long>dist;

void dij(){
    dist.assign(n+1,LLONG_MAX);
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q;
    for (int i=1;i<=n;i++){
        if (dp[i]!=LLONG_MAX){
            dist[i]=dp[i];
            q.push({dist[i],i});
        }
    }

    while (!q.empty()){
        auto [dis,node]=q.top();
        q.pop();

        if (dist[node]<dis){
            continue;
        }

        for (auto [w,newn]:adj[node]){
            if (dis+w<dist[newn]){
                dist[newn]=dis+w;
                q.push({dist[newn],newn});
            }
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m>>k;
    adj.assign(n+1,vector<pair<long long,int>>());
    dp.assign(n+1,LLONG_MAX);
    
    vector<long long>make(k+1),loc(k+1);
    for (int i=1;i<=k;i++){
        cin>>make[i];
    }
    for (int i=1;i<=k;i++){
        cin>>loc[i];
    }

    vector<vector<int>>locs(k+1,vector<int>());

    for (int i=1;i<=k;i++){
        for (int j=1;j<=loc[i];j++){
            int l;
            cin>>l;
            locs[i].push_back(l);
        }
    }

    for (int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({c,b});
        adj[b].push_back({c,a});
    }

    dp[1]=0;
    
    for (int i=1;i<=k;i++){
        vector<long long>newdp(n+1,LLONG_MAX);
        dij();
        for (auto u:locs[i]){
            newdp[u]=dist[u];
        }

        for (int v=1;v<=n;v++){
            if (dp[v]!=LLONG_MAX){
                newdp[v]=min(newdp[v],dp[v]+make[i]);
            }
        }
        dp=newdp;
    }

    long long ans=LLONG_MAX;
    for (int i=1;i<=n;i++){
        ans=min(dp[i],ans);
    }

    cout<<ans;


}
