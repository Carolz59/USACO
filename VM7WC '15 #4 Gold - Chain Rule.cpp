#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<pair<int,int>>>adj;
vector<int>dist;

void kirksdikdik(int s){
    dist.assign(n,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;

    dist[s]=0;
    q.push({0,s});

    while (!q.empty()){
        auto [d,node]=q.top();
        q.pop();

        if (dist[node]<d){
            continue;
        }

        for (auto [w,ne]:adj[node]){
            if (d+w<dist[ne]){
                dist[ne]=d+w;
                q.push({d+w,ne});
            }
        }
    }
    
}
int main(){
    cin>>n>>m;
    adj.assign(n,vector<pair<int,int>>());

    for (int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({c,b});
        adj[b].push_back({c,a});
    }

    kirksdikdik(0);
    vector<int>dists=dist;
    kirksdikdik(n-1);
    vector<int>distf=dist;

    int temp=INT_MIN;
    for (int i=0;i<n;i++){
        temp=max(dists[i]+distf[i],temp);

    }
    cout<<temp;


    
}
