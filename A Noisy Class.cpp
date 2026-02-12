#include <bits/stdc++.h>
using namespace std;

int n,m;

vector<vector<int>>adj;
vector<int>indeg;
vector<int>order;

bool topo(){
    queue<int>q;
    for (int i=1;i<=n;i++){
        if (indeg[i]==0){
            q.push(i);
            order.push_back(i);

        }

    }

    while (!q.empty()){
        int cur=q.front();
        q.pop();

        for (auto u:adj[cur]){
            indeg[u]--;
            if (indeg[u]==0){
                q.push(u);
                order.push_back(u);
            }
        }

    }

    if (order.size()==n){
        return true;
    }else{
        return false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>n>>m;

    adj.assign(n+1,vector<int>());
    indeg.assign(n+1,0);

    for (int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        indeg[b]++;
        adj[a].push_back(b);
    }

    bool yes=topo();

    if (yes){
        cout<<"Y"<<endl;
    }else{
        cout<<"N"<<endl;
    }

}
