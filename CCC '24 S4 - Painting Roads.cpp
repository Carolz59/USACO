#include <bits/stdc++.h>
using namespace std;

int n,m;

vector<vector<pair<int,int>>>adj;
vector<int>res;
vector<bool>visited;


void dfs(int s,int state){
    visited[s]=true;

    for (auto u:adj[s]){
        if (!visited[u.first]){
            res[u.second]=3-state;
            dfs(u.first,res[u.second]);
    }
        
    }
}

int main(){
    cin>>n>>m;
    adj.assign(n+1,vector<pair<int,int>>());
    res.assign(m+1,-1);
    visited.assign(n+1,false);

    for (int i=1;i<m+1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back({b,i});
        adj[b].push_back({a,i});

    }

    for (int i=1;i<n+1;i++){
        if (!visited[i]){
            dfs(i,1);
        }
    }
    
    for (int i=1;i<res.size();i++){
        if (res[i]==-1){
            cout<<"G";
        }else if (res[i]==2){
            cout<<"B";
        }else{
            cout<<"R";
        }
    }


}
