#include <bits/stdc++.h>
using namespace std;

vector<int>parent,sz;

int find(int a){
    while (a!=parent[a]){
        a=parent[a];
    }
    return a;
}

bool same(int a,int b){
    a=find(a);
    b=find(b);
    return a==b;
}

void unione(int a,int b){
    a=find(a);
    b=find(b);
    if (sz[a]<sz[b]){
        swap(a,b);
    }

    parent[b]=a;
    sz[a]+=sz[b];
}

int main(){
    int n;
    cin>>n;

    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>q;
    map<pair<int,int>,vector<int>>pens;

    sz.assign(n+1,1);
    parent.resize(n+1);
    
    map<pair<int,int>,int>weight;

    for (int i=0;i<n+1;i++){
        parent[i]=i;
    }

    for (int i=1;i<n+1;i++){
        int m;
        cin>>m;
        vector<pair<int,int>>edges(m);
        vector<int>nodes(m),wei(m);
        for (int j=0;j<m;j++){
            cin>>nodes[j];

        }
        for (int j=0;j<m;j++){
            cin>>wei[j];

        }
        for (int j=0;j<m;j++){
            int a=nodes[j];
            int b=nodes[(j+1)%m];
            if (a>b){
                swap(a,b);
            }
            pens[{a,b}].push_back(i);
            weight[{a,b}]=wei[j];
        }
    }

    for (auto z:pens){
        int w=weight[z.first];
        if (z.second.size()==1){
            q.push({w,z.second[0],0});
            
        }else{
            q.push({w,z.second[0],z.second[1]});
            
        }

    }
    int ans=0;

    while (!q.empty()){
        auto [w,u,v]=q.top();
        q.pop();

        if (!same(u,v)){
            unione(u,v);
            ans+=w;
        }
    }
    cout<<ans;
    
}
