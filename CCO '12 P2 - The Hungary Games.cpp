#include <bits/stdc++.h>
using namespace std;

long long n,m;

vector<vector<pair<long long,long long>>>adj;
vector<pair<long long,long long>>dist;

void kirksdikdik(long long s){
    dist.assign(n+1,{LLONG_MAX,LLONG_MAX});
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>q;
    q.push({0,s});
    dist[s].first=0;

    while (!q.empty()){
        auto [d,n2]=q.top();
        q.pop();

        if (dist[n2].second<d){
            continue;
        }

        for (auto [w,n1]:adj[n2]){
            long long dis=w+d;
            if (dis<dist[n1].first){
                dist[n1].second=dist[n1].first;
                dist[n1].first=dis;
                q.push({dis,n1});

            }else if (dis>dist[n1].first&&dis<dist[n1].second){
                dist[n1].second=dis;
                q.push({dis,n1});
            }
        }
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;

    adj.assign(n+1,vector<pair<long long,long long>>());
    
    

    for (int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({c,b});


    }

    kirksdikdik(1);
    if (dist[n].second==LLONG_MAX){
        cout<<-1;
        return 0;
    }
    cout<<dist[n].second;
    

}
