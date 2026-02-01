#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<pair<long long,long long>>>adj;
vector<long long>ans;


void dij(){
    priority_queue<pair<long long,long long>>q;
    q.push({LLONG_MAX,1});

    while (!q.empty()){
        auto [best,node]=q.top();
        q.pop();
        if (best<ans[node]){
            continue;
        }

        for (auto&[w,v]:adj[node]){
            long long maybe=min(w,best);
            if (maybe>ans[v]){
                ans[v]=maybe;
                q.push({maybe,v});
            }
        }
    }
}

int main(){
    cin>>n>>m;
    adj.assign(n+1,vector<pair<long long,long long>>());
    ans.assign(n+1,0);

    for (int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;

        adj[a].push_back({c,b});
        adj[b].push_back({c,a});
    }

    dij();
    cout<<0<<endl;
    for (int i=2;i<n+1;i++){
        cout<<ans[i]<<endl;
    }

}
