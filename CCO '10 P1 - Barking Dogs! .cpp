#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<int>w(n+1);

    for (int i=1;i<=n;i++){
        cin>>w[i];
    }

    int b;
    cin>>b;
    vector<vector<int>>adj(n+1,vector<int>());
    for (int i=0;i<b;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);

    }

    int t;
    cin>>t;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    q.push({0,1});
    vector<int>cnt(n+1,0);
    vector<int>cooldown(n+1,0);
    cnt[1]++;
    cooldown[1]=1;
    int time=0;
    while (!q.empty()){
        auto[time,dog]=q.top();
        q.pop();

        if (time>t){
            break;
        }
        
        for (auto u:adj[dog]){
            if (time>=cooldown[u]){
                int bark=w[u]+time;
                if (bark<=t){
                    cnt[u]++;
                }
                q.push({bark,u});
                cooldown[u]=bark+1;
            }

        }
    }

    for (int i=1;i<=n;i++){
        cout<<cnt[i]<<endl;
    }



    
}
