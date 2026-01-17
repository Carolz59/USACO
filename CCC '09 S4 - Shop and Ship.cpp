#include <bits/stdc++.h>
using namespace std;
int num,t;

vector<vector<pair<int,int>>>adj;
vector<int>dist;
void dij(int s){
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    dist[s]=0;
    q.push({0,s});

    while (!q.empty()){
        int n=q.top().second;
        int w=q.top().first;
        q.pop();

        if (w>dist[n]){
            continue;
        }
        
        for (auto u:adj[n]){
            int wei=u.first;
            int no=u.second;

            if (dist[n]+wei<dist[no]){
                dist[no]=dist[n]+wei;
                q.push({dist[no],no});
            }
            
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>num>>t;
    adj.assign(num+1,vector<pair<int,int>>());
    dist.assign(num+1,INT_MAX);

    for (int i=0;i<t;i++){
        int a,b,w;
        cin>>a>>b>>w;
        adj[a].push_back({w,b});
        adj[b].push_back({w,a});

    }
    int k;
    cin>>k;

    vector<pair<int,int>>source(k);
    vector<int>cost(k);

    for(int i=0;i<k;i++){
        int x,c;
        cin>>x>>c;
        source[i]={x,c};

    }
    int d; cin>>d;
    int smol=INT_MAX;

    dij(d);

    for (int i=0;i<k;i++){
        if (source[i].first==d){
            cost[i]=source[i].second;
        }else{
            cost[i]=source[i].second+dist[source[i].first];
            
        }
        if (cost[i]<smol){
            smol=cost[i];
        }
    }
    cout<<smol<<endl;

}
