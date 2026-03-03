#include<bits/stdc++.h>
using namespace std;

int t,n;
vector<vector<pair<int,int>>>adj;
vector<int>dist;

int dij(int s,int f){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    dist[s]=0;
    q.push({0,s});

    while (!q.empty()){
        auto [dis,node]=q.top();
        q.pop();

        if (dis>dist[node]){
            continue;
        }
        if (node==f){
            return dis;
        }

        for (auto [w,newnode]:adj[node]){
            if ((node==s&&newnode==f)||(node==f&&newnode==s)){
                continue;
            }
            if (dis+w<dist[newnode]){
                dist[newnode]=dis+w;
                q.push({dis+w,newnode});
            }
        }
    }
    return INT_MAX;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>t;

    for (int i=0;i<t;i++){
        cin>>n;
        adj.assign(n+1,vector<pair<int,int>>());
        
        for (int r=1;r<=n;r++){
            for (int c=1;c<=n;c++){
                int w;
                cin>>w;
                if (w==-1){
                    continue;
                }
                adj[r].push_back({w,c});
                adj[c].push_back({w,r});
            }
        }

        int ans=INT_MAX;

        for (int r=1;r<=n;r++){
            for (auto [d,no]:adj[r]){
                if (r>no){
                    continue;
                }
                dist.assign(n+1,INT_MAX);
                int dis=dij(r,no);
                if (dis==INT_MAX){
                    continue;
                }
                ans=min(dis+d,ans);
            }
        }

        if (ans==INT_MAX){
            cout<<"Infinity"<<endl;
        }else{
            cout<<ans<<endl;
        }
    }

    
}
