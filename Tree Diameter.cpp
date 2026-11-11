#include<bits/stdc++.h>
using namespace std;

long long n;
vector<vector<long long>>adj;
vector<long long>dist;
queue<long long>q;
long long far,no;
pair<long long,long long> bfs(long long s){
    far=0;
    q.push(s);
    dist[s]=0;
    while (!q.empty()){
        long long cur=q.front();
        q.pop();

        for (auto u:adj[cur]){
            if (dist[u]==-1){
                dist[u]=dist[cur]+1;
                q.push(u);;
                if (dist[u]>far){
                    far=dist[u];
                    no=u;
                }
            }
        }
    }
    return {far,no};

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    adj.assign(n+1,vector<long long>());
    dist.assign(n+1,-1);

    for (int i=0;i<n-1;i++){
        long long u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    auto [a,b]=bfs(1);
    dist.assign(n+1,-1);
    q=queue<long long>();
    auto [c,d]=bfs(b);
    cout<<c;
    
}
