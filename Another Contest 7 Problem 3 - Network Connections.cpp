#include <bits/stdc++.h>
using namespace std;

long long n,m;
vector<long long>parent,sz;

long long find(long long a){
    if (parent[a]!=a){
        parent[a]=find(parent[a]);
    }
    return parent[a];
}

bool same(long long a,long long b){
    return find(a)==find(b);
}

void uni(long long a,long long b){
    a=find(a);
    b=find(b);

    if (a<b){
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

    for (int i=1;i<=n;i++){
        parent[i]=i;
    }

    vector<long long>f(n+1);
    for (int i=1;i<=n;i++){
        cin>>f[i];
    }

    priority_queue<tuple<long long,long long,long long>,vector<tuple<long long,long long,long long>>,greater<tuple<long long,long long,long long>>>q;
    for (long long i=2;i<=n;i++){
        q.push({abs(f[i]-f[i-1]),i,i-1});
    }

    for (int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        if (!same(a,b)){
            uni(a,b);
        }
    }

    int cost=0;
    while (!q.empty()){
        auto [w,u,v]=q.top();
        q.pop();
        if (!same(u,v)){
            uni(u,v);
            cost+=w;
        }
    }

    cout<<cost<<endl;
    
}
