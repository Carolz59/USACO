#include <bits/stdc++.h>

using namespace std;

pair<int,int> leng(int start,vector<vector<int>>&adj,vector<int>&visited){
    queue<int>q;
    q.push(start);
    visited[start]=0;

    while (!q.empty()){
        int cur=q.front();
        q.pop();

        for (int i=0;i<adj[cur].size();i++){
            int nei=adj[cur][i];
            if (visited[nei]==-1){
                q.push(nei);
                visited[nei]=visited[cur]+1;
            }
        }
    }
    int max=0;
    int index;
    for (int i=0;i<visited.size();i++){
        if (visited[i]>max){
            max=visited[i];
            index=i;
        }
    }
    return make_pair(max,index);
}
int main(){
    int n;
    cin>>n;
    int a,b;
    vector<vector<int>>adj(n+1);
    vector<int>visited(n+1,-1);
    for (int i=0;i<n-1;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int start=1;

    int n1=leng(start,adj,visited).second;
    visited.assign(n+1,-1);

    int n2=leng(n1,adj,visited).first;


    cout<<n2<<endl;


    
}
