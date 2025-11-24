#include <bits/stdc++.h>
using namespace std;

struct Pair{
    int x,y;
    Pair(int _x,int _y):x(_x),y(_y){}
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;

    vector<vector<Pair>> adj(n+1);
    for(int i=0;i<m;i++){
        int a,b,d;
        cin>>a>>b>>d;
        adj[a].push_back(Pair(b,d));
    }

    vector<array<int,2>> dis(n+1);
    for(int i=0;i<=n;i++){
        dis[i][0]=INT_MAX;
        dis[i][1]=INT_MAX;
    }
    dis[1][0]=0;

    auto cmp=[](const Pair&a,const Pair&b){
        return a.y>b.y;
    };

    priority_queue<Pair,vector<Pair>,decltype(cmp)> pq(cmp);
    pq.push(Pair(1,0));

    while(!pq.empty()){
        Pair p=pq.top();
        pq.pop();
        if(p.y>dis[p.x][1]) continue;
        for(auto nxt:adj[p.x]){
            int nd=p.y+nxt.y;
            if(nd<dis[nxt.x][0]){
                int t=dis[nxt.x][0];
                dis[nxt.x][0]=nd;
                dis[nxt.x][1]=t;
                pq.push(Pair(nxt.x,dis[nxt.x][0]));
            }else if(nd<dis[nxt.x][1]&&nd!=dis[nxt.x][0]){
                dis[nxt.x][1]=nd;
                pq.push(Pair(nxt.x,dis[nxt.x][1]));
            }
        }
    }

    if(dis[n][1]==INT_MAX) cout<<-1<<"\n";
    else cout<<dis[n][1]<<"\n";

    return 0;
}
