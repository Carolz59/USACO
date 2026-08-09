#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<vector<int>>adj(n+1,vector<int>());
    vector<int>d(n+1);
    for (int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        d[a]++;
        d[b]++;

    }

    queue<int>q;

    for (int i=1;i<=n;i++){
        if (d[i]==1){
            q.push(i);
        }
    }

    vector<bool>used(n+1,false);
    int ans=0;

    while (!q.empty()){
        auto u=q.front();
        q.pop();
        int p=-1;

        for (auto v:adj[u]){
            if (!used[v]){
                p=v;
                break;
            }
        }
        if (p!=-1){
            ans++;
            used[p]=true;
            used[u]=true;
            for (auto rest:adj[p]){
                d[rest]--;
                if (!used[rest]&&d[rest]==1){
                    q.push(rest);
                }
            }
        }else{
            continue;
        }
        


    }
    cout<<ans;


    
    
}
