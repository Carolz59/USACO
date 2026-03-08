#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int>parent,sz;
vector<vector<int>>e,f;

int find(int a){
    if (parent[a]!=a){
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

    sz[a]+=sz[b];
    parent[b]=a;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;
    sz.assign(n+1,1);
    parent.resize(n+1);
    e.assign(n+1,vector<int>());
    for (int i=1;i<=n;i++){
        parent[i]=i;
    }

    for (int i=0;i<m;i++){
        char t;
        int u,v;
        cin>>t>>u>>v;
        if(t=='E'){
            e[u].push_back(v);
            e[v].push_back(u);
        }else{
            if (!same(u,v)){
                uni(u,v);
            }
        }
    }

    for (int i=1;i<=n;i++){
        int prev;
        for (int j=0;j<e[i].size();j++){
            if (j==0){
                prev=e[i][0];
                continue;
            }else{
                uni(prev,e[i][j]);
            }
        }
    }

    int comp=0;
    for (int i=1;i<=n;i++){
        if (find(i)==i){
            comp++;
        }
    }

    cout<<comp<<endl;

   

}
