#include <bits/stdc++.h>
using namespace std;

int k,n,m;
vector<vector<int>>dist; //dist[node][damage]=mintime
vector<vector<tuple<int,int,int>>>adj; //adj[node1]={time,hulldmg,node2}

int dij(int start,int finish){
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>q;
    //{time,hull,node}
    dist[start][0]=0;
    q.push({0,0,start});

    while (!q.empty()){
        auto [time,hull,node]=q.top();
        q.pop();

        if (time>dist[node][hull]){
            continue;
        }
        if (node==finish){
            return time;
        }

        for (auto [t,h,no]:adj[node]){
            int usage=hull+h;
            if (usage>=k){
                continue;
            }
            if((t+time)<dist[no][usage]){
                dist[no][usage]=t+time;
                q.push({t+time,usage,no});
            }
        }
    }

    return -1;


}

int main(){
    cin>>k>>n>>m;
    dist.assign(n+1,vector<int>(k,INT_MAX));
    adj.assign(n+1,vector<tuple<int,int,int>>());


    for (int i=0;i<m;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        adj[a].push_back({c,d,b});
        adj[b].push_back({c,d,a});
    }
    int s,f;
    cin>>s>>f;


    cout<<dij(s,f);


}
