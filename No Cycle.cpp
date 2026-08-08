#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    long long m,k;
    cin>>n>>m>>k;
    vector<vector<long long>>adj(n+1,vector<long long>());
    vector<long long>indeg(n+1,0);

    for (int i=0;i<m;i++){
        long long u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        indeg[v]++;

    }
    queue<long long>q;
    for (int i=1;i<=n;i++){
        if (indeg[i]==0){
            q.push(i);

        }
    }
    vector<long long>order,pos(n+1);
    while (!q.empty()){
        auto cur=q.front();
        q.pop();
        order.push_back(cur);
        for (auto z:adj[cur]){
            indeg[z]--;
            if (indeg[z]==0){
                q.push(z);
            }
        }
    }
    if (order.size()!=n){
        cout<<-1<<endl;
        return 0;

    }
    for (int i=0;i<n;i++){
        pos[order[i]]=i;

    }
    vector<pair<long long,long long>>ans;
    while (k--){
        long long u,v;
        cin>>u>>v;
        if (pos[u]>pos[v]){
            ans.push_back({v,u});
        }else{
            ans.push_back({u,v});
        }
    }

    for (auto [a,b]:ans){
        cout<<a<<" "<<b<<endl;
    }

    
}
