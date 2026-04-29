#include<bits/stdc++.h>
using namespace std;

int n,m,k;
vector<vector<int>>adj,rev;
vector<int>dist;

vector<int> bfs(vector<vector<int>>v){
    dist.assign(n+1,-1);
    queue<int>q;
    dist[1]=0;
    q.push(1);

    while(!q.empty()){
        int cur=q.front();
        q.pop();

        for (auto u:v[cur]){
            if (dist[u]==-1){
                dist[u]=dist[cur]+1;
                q.push(u);
            }
            
        }

    }
    return dist;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;
    adj.assign(n+1,vector<int>());
    rev.assign(n+1,vector<int>());
    for (int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        rev[v].push_back(u);


    }
    cin>>k;
    int tot=0;

    vector<int> ans1=bfs(adj);
    vector<int> ans2=bfs(rev);
    for (int i=0;i<k;i++){
        int t;
        cin>>t;
        
        if (ans1[t]==-1||ans2[t]==-1){
            cout<<-1<<endl;
            return 0;
        }else{
            tot+=ans1[t]+ans2[t];
        }
    }

    cout<<tot;



}
