#include<bits/stdc++.h>

using namespace std;

int n=10000;
vector<vector<int>>adj(n);

int bfs(int n, const vector<int>& offices){
    queue<int>q;
    vector<int>dist(n+1,-1);
    int time=0;

    for (auto & u:offices){
        q.push(u);
        dist[u]=0;


    }

    while (!q.empty()){
        int cur=q.front();
        q.pop();

        for (int i=0;i<adj[cur].size();i++){
            int nei=adj[cur][i];
            if (dist[nei]==-1){
                dist[nei]=dist[cur]+1;
                q.push(nei);
            }

        }
        for (int i=1;i<n+1;i++){
            time=max(time,dist[i]);
        }
        


    }
    return time;
    

}

int main(){
    int n,m,k;
    cin>>n>>m;
    int a,b;

    adj.assign(n+1,{});
    for (int i=0;i<m;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cin>>k;
    int p;
    vector<int>offices;

    for (int i=0;i<k;i++){
        cin>>p;
        offices.push_back(p);
    }
    cout<<bfs(n,offices)<<endl;

    
}
