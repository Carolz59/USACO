#include<bits/stdc++.h>
using namespace std;

long long n;
vector<vector<long long>>adj;
vector<bool>imp;
vector<long long>dist;

bool prune(long long u,long long p){
    for (auto v:adj[u]){
        if (v==p){
            continue;
        }
        if (prune(v,u)){
            imp[u]=true;
        }
    }
    return imp[u];
}
long long far,node;
void bfs(long long u){
    dist[u]=0;
    node=u;
    far=0;
    queue<long long>q;
    q.push(u);
    while (!q.empty()){
        long long u=q.front();
        q.pop();

        for (auto v:adj[u]){
            if (imp[v]&&dist[v]==-1){
                q.push(v);
                dist[v]=dist[u]+1;
                if (dist[v]>far){
                    far=dist[v];
                    node=v;
                }

            }
        }
    }
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    long long m;
    cin>>m;
    adj.assign(n,vector<long long>());
    dist.assign(n,-1);
    imp.assign(n,false);
    long long use;
    while(m--){
        long long z;
        cin>>z;
        imp[z]=true;
        use=z;
    }

    for (int i=1;i<n;i++){
        long long u,v;
        cin>>u>>v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    prune(use,-1);
    bfs(use);
    dist.assign(n,-1);
    bfs(node);
    long long e=-1;

    for (int i=0;i<n;i++){
        if (imp[i]){
            e++;
        }
    }

    cout<<2*e-far;



    
}
