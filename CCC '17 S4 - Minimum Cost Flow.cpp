//11/15, ill take this deadass on the contest

#include <bits/stdc++.h>
using namespace std;

int n,m,d;

vector<int>sz,parent;

int find(int a){
    while (parent[a]!=a){
        a=parent[a];
    }
    return a;
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

bool same(int a,int b){
    a=find(a);
    b=find(b);
    return a==b;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>d;
    sz.assign(n+1,1);
    parent.assign(n+1,-1);
    map<pair<int,int>,pair<bool,int>>cur;//edge:{used,wei}
    priority_queue<tuple<int,int,int,int>,vector<tuple<int,int,int,int>>,greater<tuple<int,int,int,int>>>q;

    //weight,exist,a,b;

    for (int i=1;i<n+1;i++){
        parent[i]=i;
    }

    for (int i=0;i<n-1;i++){
        int x,y,z;
        cin>>x>>y>>z;
        q.push({z,0,x,y});
        cur[{min(x,y),max(x,y)}]={false,z};
    }
    for (int i=n-1;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        q.push({z,1,x,y});
        
    }



    int add=0;
    

    while (!q.empty()){
        auto [w,e,u,v]=q.top();
        q.pop();
        if (!same(u,v)){
            unione(u,v);
            if (e==0){
                cur[{min(u,v),max(u,v)}].first=true;

            }else{
                add++;
            }
            
        }
    }

    for (auto&[edge,info]:cur){
        auto&[used,weight]=info;
        if (!used&&weight<=d){
            add--;
            break;
        }
    }
    
    cout<<add;
    

    
}
