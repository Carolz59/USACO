#include <bits/stdc++.h>
using namespace std;

int n,m;

vector<vector<pair<int,int>>>adj; //adj[u]={danger,v}
vector<pair<int,int>>dist; //dist[u]={min danger,min dist}

pair<int,int> dik(){
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>q;//{danger,tot,node}
    q.push({0,0,1});
    dist[1]={0,0};

    while (!q.empty()){
        auto [danger,tot,u]=q.top();
        q.pop();

        if (danger>dist[u].first){
            continue;
        }
        if (danger==dist[u].first&&tot>dist[u].second){
            continue;
        }

        if (u==n){
            return {danger,tot};
        }

        for (auto [dang,v]:adj[u]){
            auto [vdang,vdist]=dist[v];
            if (danger+dang<vdang){
                dist[v]={danger+dang,dist[u].second+1};
                q.push({danger+dang,dist[u].second+1,v});
            }else if(danger+dang==vdang&&dist[u].second+1<vdist){
                dist[v]={danger+dang,dist[u].second+1};
                q.push({danger+dang,dist[u].second+1,v});
            }
        }
    }
    return {-1,-1};


}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;

    adj.assign(n+1,vector<pair<int,int>>());
    dist.assign(n+1,{INT_MAX,INT_MAX});

    for (int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({c,b});
        adj[b].push_back({c,a});
    }

    auto [x,y]=dik();

    if (x==-1&&y==-1){
        cout<<-1<<endl;
        return 0;
    }

    cout<<x<<" "<<y<<endl;

    

    
    
}
