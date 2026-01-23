#include <bits/stdc++.h>
using namespace std;

long long n,m;
vector<vector<pair<long long,long long>>>adj;
vector<long long>edge;
vector<long long>best;
long long res=LLONG_MAX;

void dij(long long start, long long target){
    priority_queue<tuple<long long,long long,long long>,vector<tuple<long long,long long,long long>>,greater<tuple<long long,long long,long long>>>q; //tot cost,cur node,prev edge
    q.push({0,start,m+1});
    best[m+1]=0;
    

    while (!q.empty()){
        auto [cost,node,prev]=q.top();
        q.pop();

        if (cost>best[prev]){
            continue;
        }

        if (node==target){
            res=min(res,cost);
            continue;
        }
        
        for (auto u:adj[node]){
            long long nextedge=u.second;
            long long nextnode=u.first;
            long long newcost=cost;
            newcost=cost+abs(edge[nextedge]-edge[prev]);

            if (newcost<best[nextedge]){
                best[nextedge]=newcost;
                q.push({best[nextedge],nextnode,nextedge});
            }

        }

    }

}

int main(){
    cin>>n>>m;
    adj.assign(n+1,vector<pair<long long,long long>>());
    edge.resize(m+2);
    best.assign(m+2,LLONG_MAX);

    for (long long i=1;i<m+1;i++){
        long long a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,i});
        adj[b].push_back({a,i});
        edge[i]=c;
    }

    dij(1,n);

    cout<<res;
    




}
