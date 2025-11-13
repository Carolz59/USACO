#include <bits/stdc++.h>
using namespace std;

int n=10000;
int node,gyms;
vector<bool>gym;
vector<bool>keep;
vector<vector<int>>adj;
vector<int>visited;

bool prune(int u,int p){
    bool imp=gym[u];
    for (int v:adj[u]){
        if (v==p){
            continue;
        }
        if (prune(v,u)==true){
            imp=true;
        }
    }
    keep[u]=imp;
    return imp;

}

int distnodragon(int s){
    queue<int>process;
    process.push(s);
    visited[s]=0;
    while(!process.empty()){
        int cur=process.front();
        process.pop();
        for (int v:adj[cur]){
            if (visited[v]==-1&&keep[v]){
                visited[v]=visited[cur]+1;
                process.push(v);
            }
        }
    }
    int nmax=0;
    for (int x:visited){
        if (x>nmax){
            nmax=x;
        }
    }
    return nmax;
}

int main(){
    int c;
    int t,x,y;
    cin>>node>>gyms>>c;

    gym.assign(node+1,false);
    keep.assign(node+1,false);
    adj.assign(node+1,{});
    visited.assign(node+1,-1);

    for (int i=0;i<gyms;i++){
        cin>>t;
        gym[t]=true;
    }
    for (int i=0;i<node-1;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    prune(1,-1);
    int count=0;
    for (int i:keep){
        if (i==true){
            count++;
        }
    }
    

    int nodragon=2*(count-1)-distnodragon(1);
    fill(keep.begin(), keep.end(), false);

    gym[c]=true;
    fill(visited.begin(),visited.end(),-1);
    prune(1,-1);
    int count2=0;
    for (bool i:keep){
        if (i==true){
            count2++;
        }
    }
    int dragon=count2-1;
    cout<<min(nodragon,dragon);

    

}
