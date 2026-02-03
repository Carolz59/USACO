#include <bits/stdc++.h>
using namespace std;

long long n,m;
vector<vector<pair<long long,long long>>>adj;
vector<long long>ans;
priority_queue<pair<long long,long long>>q;
void dij(){

    while (!q.empty()){
        auto [a,node]=q.top();
        q.pop();
        if (a<ans[node]){
            continue;
        }

        for (auto [w,u]:adj[node]){
            if (ans[node]-w>ans[u]){
                ans[u]=ans[node]-w;
                q.push({ans[u],u});
            }
        }
    }



}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    adj.assign(n+1,vector<pair<long long,long long>>());
    ans.assign(n+1,0);

    for (int i=1;i<n+1;i++){
        int num;
        cin>>num;
        ans[i]=num;
        q.push({ans[i],i});

    }

    for (int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({c,b});
        adj[b].push_back({c,a});
    }

    dij();

    for (int i=1;i<n+1;i++){
        cout<<ans[i]<<endl;
    }

}
