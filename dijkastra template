#include <bits/stdc++.h>
using namespace std;

int n;
vector<int>dist(n+1);
vector<bool>visited(n+1,false);
vector<vector<pair<int,int>>>adj(n+1); //weight,node

void dik(int s){
    dist[s]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q; //{dist, node}
    q.push({0,s});

    while (!q.empty()){
        int a=q.top().second;
        q.pop();

        if (visited[a]==true){
            continue;
        }
        visited[a]=true;

        for (auto u:adj[a]){
            int weight=u.first;
            int node=u.second;

            if ((dist[a]+weight)<dist[node]){
                dist[node]=dist[a]+weight;
                q.push({dist[node],node});

            }


        }

            

        }
    

    


}


int main(){

    cin>>n;
    int m;
    cin>>m;
    dist.assign(n+1,INT_MAX);
    visited.assign(n+1,false);
    adj.assign(n+1,vector<pair<int,int>>());

    for (int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        adj[a].push_back({w,b});
        adj[b].push_back({w,a});

    }

    for (int i=1;i<=n;i++){
        dist[i]=INT_MAX;

    }
    dik(1);

    for (int i=1;i<dist.size();i++){
        if (dist[i]==INT_MAX){
            cout<<-1<<endl;
        }else{
            cout<<dist[i]<<endl;
        }
    }



}
