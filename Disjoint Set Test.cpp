#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int>parent,sz;

int find(int a){
    if (a!=parent[a]){
        parent[a]=find(parent[a]);
    }
    return parent[a];
}

bool same(int a,int b){
    return find(a)==find(b);
}

void uni(int a,int b){
    a=find(a);
    b=find(b);
    if (sz[a]<sz[b]){
        swap(a,b);
    }
    parent[b]=a;
    sz[a]+=sz[b];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>q;
    parent.resize(n+1);
    sz.assign(n+1,1);

    for (int i=1;i<=n;i++){
        parent[i]=i;
    }



    for (int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        q.push({i,a,b});
        
    }
    
    vector<int>mst;
    while (!q.empty()){
        auto [w,u,v]=q.top();
        q.pop();

        if (!same(u,v)){
            uni(u,v);
            mst.push_back(w);
            
        }

    }

    if (mst.size()==n-1){
        for (auto u:mst){
            cout<<u<<endl;
        }
    }else{
        cout<<"Disconnected Graph"<<endl;
    }

    
    

    
}
