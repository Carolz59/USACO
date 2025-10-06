#include<bits/stdc++.h>

using namespace std;

int s=10000;
vector<bool>visited(s,false);
vector<vector<int>>adj(s);
bool cantheyfuck = false;
void dfs(int start,int finish){
    if (visited[start]==true){
        return;
    }
    visited[start]=true;
    if (start==finish){
        cantheyfuck=true;
        
    }
    for (int i=0;i<adj[start].size();i++){
        dfs(adj[start][i],finish);
    }
}
int main(){
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    int x,y;
    
    adj.assign(n,{});
    visited.assign(n,0);
    for (int i=0;i<m;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(a,b);
    if (cantheyfuck==true){
        cout<<"GO SHAHIR!"<<endl;

    }else{
        cout<<"NO SHAHIR!"<<endl;
    }
    
    

}
