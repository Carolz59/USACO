#include <bits/stdc++.h>
using namespace std;

int n,m,dest;
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
    cin>>n>>m>>dest;
    parent.resize(n+1);
    sz.assign(n+1,1);

    for (int i=1;i<n+1;i++){
        parent[i]=i;
    }

    priority_queue<tuple<int,int,int>>q;

    for (int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        q.push({w,u,v});
        
    }
    set<int>mustv;
    for (int i=0;i<dest;i++){
        int must;
        cin>>must;
        mustv.insert(must);

    }

    int ans=-1;
    

    while (!q.empty()){
        auto [w,u,v]=q.top();
        q.pop();

        
        
        if (!same(u,v)){
            unione(u,v);
        }

        bool connected=true;
        for (auto node:mustv){
            if (find(node)!=find(1)){
                connected=false;
                break;
            }
        }
        if (connected){
            ans=w;
            break;
        }
        
    }
    cout<<ans;

    
}
