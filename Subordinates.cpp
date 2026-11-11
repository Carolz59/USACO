#include<bits/stdc++.h>
using namespace std;

long long n;
vector<vector<long long>>adj;
vector<long long>sub;

void dfs(long long s){
    for (auto u:adj[s]){
        dfs(u);
        sub[s]+=1+sub[u];
    }

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    adj.assign(n+1,vector<long long>());
    sub.assign(n+1,0);

    for (int i=1;i<n;i++){
        long long z;
        cin>>z;
        adj[z].push_back(i+1);
    }
    dfs(1);

    for (int i=1;i<=n;i++){
        cout<<sub[i]<<endl;
    }
    
    
}
