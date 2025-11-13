#include <bits/stdc++.h>
using namespace std;
const int MM=1e5+5;
int N,M;
bool pho[MM],keep[MM];
vector<int> adj[MM];
bool dfs_prune(int u,int p){
    bool imp=pho[u];
    for(int v:adj[u]){
        if(v==p)continue;
        if(dfs_prune(v,u))imp=1;
    }
    keep[u]=imp;
    return imp;
}
pair<int,int> dfs_far(int u,int p,int d){
    pair<int,int> res={u,d};
    for(int v:adj[u]){
        if(v==p||!keep[v])continue;
        auto cur=dfs_far(v,u,d+1);
        if(cur.second>res.second)res=cur;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    vector<int> phoList(M);
    for(int i=0;i<M;i++){
        cin>>phoList[i];
        pho[phoList[i]]=1;
    }
    for(int i=0;i<N-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs_prune(phoList[0],-1);
    int edgeCount=0;
    for(int u=0;u<N;u++){
        if(!keep[u])continue;
        for(int v:adj[u]){
            if(keep[v]&&v>u)edgeCount++;
        }
    }
    int start=phoList[0];
    while(!keep[start])start++;
    int A=dfs_far(start,-1,0).first;
    int diameter=dfs_far(A,-1,0).second;
    cout<<2*edgeCount-diameter<<"\n";
    return 0;
}
