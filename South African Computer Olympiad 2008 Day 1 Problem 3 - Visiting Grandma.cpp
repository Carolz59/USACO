#include<bits/stdc++.h>
using namespace std;

long long n;
long long mod=1000000;
vector<vector<pair<long long,long long>>>adj;
vector<long long>dist1,dist2;
vector<long long>ways1,ways2;

void dij(long long s,vector<long long>&dist,vector<long long>&ways){
    dist[s]=0;
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>q;
    q.push({0,s});
    ways[s]=1;

    while (!q.empty()){
        auto [d,node]=q.top();
        q.pop();
        if (d>dist[node]){
            continue;
        }


        for (auto [w,newn]:adj[node]){
            if (w+d==dist[newn]){
                ways[newn]=(ways[newn]+ways[node])%mod;
            }
            if (w+d<dist[newn]){
                q.push({w+d,newn});
                dist[newn]=w+d;
                ways[newn]=ways[node]%mod;
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    adj.assign(n+1,vector<pair<long long,long long>>());
    dist1.assign(n+1,LLONG_MAX/2);
    dist2.assign(n+1,LLONG_MAX/2);
    ways1.resize(n+1);
    ways2.resize(n+1);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            long long w;
            cin>>w;
            if (i==j){
                continue;
            }
            adj[i].push_back({w,j});
        }
    }
    long long ans=0;
    long long q;
    cin>>q;
    dij(1,dist1,ways1);
    dij(n,dist2,ways2);
    vector<pair<long long,long long>>huh;
    for (int i=1;i<=n;i++){
        huh.push_back({dist1[i],i});
    }
    sort(huh.begin(),huh.end());
    vector<long long>dp(n+1),cookie(n+1);
    dp[1]=1;
    while (q--){
        long long c;
        cin>>c;
        cookie[c]=1;

    }
    long long ansdist=LLONG_MAX/2;
    for(long long i=1;i<=n;i++){
        if(cookie[i]&&dist1[i]<LLONG_MAX/2&&dist2[i]<LLONG_MAX/2){
            ansdist=min(ansdist,dist1[i]+dist2[i]);
        }
    }

    if(ansdist==LLONG_MAX/2){
        cout<<0<<" "<<0;
        return 0;
    }

    for (auto [d,u]:huh){
        if (d>=LLONG_MAX/2){
            continue;
        }
        if (cookie[u]&&dist1[u]+dist2[u]==ansdist){
            ans=(ans+(__int128)dp[u]*ways2[u])%mod;
            dp[u]=0;
        }
        for (auto [w,v]:adj[u]){
            if (dist1[u]+w==dist1[v]){
                dp[v]=(dp[v]+dp[u])%mod;
            }
        }

        
    }
    cout<<ansdist<<" "<<ans;

    

    
    

}
