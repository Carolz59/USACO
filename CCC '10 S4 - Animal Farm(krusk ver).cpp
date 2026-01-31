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

    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>q,q2;
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
            q2.push({w,z.second[0],z.second[1]});
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
    

    int comp=0;
    for (int i=1;i<n+1;i++){
        if (find(i)==i){
            comp++;
        }
    }
    sz.assign(n+1,1);
    for (int i=1;i<n+1;i++){
        parent[i]=i;
    }

    if (comp==1){
        int ans2=0;
        while (!q2.empty()){
            
            auto [w,u,v]=q2.top();
            q2.pop();

            if (!same(u,v)){
                unione(u,v);
                ans2+=w;
                
        }
    }
    cout<<min(ans,ans2);
    return 0;




    }
    cout<<ans;
    
}
