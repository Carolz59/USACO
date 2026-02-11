#include <bits/stdc++.h>
using namespace std;

int n;

vector<int>dist;
vector<vector<int>>adj;
pair<int,int> bfs(int s){
    dist.assign(n+1,-1);
    queue<int>q;
    q.push(s);
    dist[s]=0;
    int endnode;
    int enddist=0;

    while (!q.empty()){
        int cur=q.front();
        q.pop();

        for (auto u:adj[cur]){
            if (dist[u]==-1){
                dist[u]=dist[cur]+1;
                q.push(u);
                if (dist[u]>enddist){
                    enddist=dist[u];
                    endnode=u;
                }
            }
        }
    }

    return {endnode,enddist};


}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    adj.assign(n+1,vector<int>());

    for (int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    auto [targ,di]=bfs(1);
    auto [targ2,dia]=bfs(targ);

    cout<<dia<<endl;

}
