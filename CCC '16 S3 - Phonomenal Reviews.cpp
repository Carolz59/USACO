#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<bool>imp;
vector<vector<int>>adj;

bool prune(int u,int p){

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

vector<int>dist;
pair<int,int> dia(int p){
    dist.assign(n,-1);
    dist[p]=0;
    queue<int>q;
    q.push(p);
    int fardist=0;
    int farnode=p;

    while (!q.empty()){
        int node=q.front();
        q.pop();
        

        for (auto ch:adj[node]){
            if (dist[ch]==-1&&imp[ch]){
                dist[ch]=dist[node]+1;
                q.push(ch);

                if (dist[ch]>fardist){
                    fardist=dist[ch];
                    farnode=ch;

                }
            }
            
        }
        
    }
    return make_pair(fardist,farnode);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    adj.assign(n,vector<int>());
    imp.assign(n,false);

    int use;
    for (int i=0;i<m;i++){
        int ph;cin>>ph;
        imp[ph]=true;
        use=ph;
    }

    for (int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    prune(use,-1);

    int edge=0;

    for (int i=0;i<imp.size();i++){
        if (imp[i]){
            edge++;
        }
    }
    edge--;

    auto [a,b]=dia(use);
    auto [c,d]=dia(b);

    int ans=2*edge-c;

    cout<<ans;





    
}
