#include <bits/stdc++.h>
using namespace std;

int n,m;
map<string,pair<string,int>>parent;

pair<string,int> find(string a){
    if (a!=parent[a].first){
        auto [news,re]=find(parent[a].first);
        parent[a].second=(parent[a].second+re)%2;
        parent[a].first=news;
        return {parent[a].first,parent[a].second};
        
    }

    return {a,parent[a].second};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    bool waterloo=false;
    for (int i=0;i<n;i++){
        string a,b,c;
        cin>>a>>b>>c;
        int rel;
        if (c=="intersect"){
            rel=1;
        }else{
            rel=0;
        }

        if (!parent.count(a)){
            parent[a]={a,0};
        }
        if (!parent.count(b)){
            parent[b]={b,0};
        }
        
        

        auto [root1,rela1]=find(a);
        auto [root2,rela2]=find(b);

        if (root1==root2){
            if ((rela1+rela2)%2!=rel){
                waterloo=true;
            }
        }else{
            parent[root2]={root1,(rel+rela1+rela2)%2};
        }


    }

    if (waterloo){
        cout<<"Waterloo"<<endl;
        return 0;
    }

    for (int i=0;i<m;i++){
        string x,y;
        cin>>x>>y;

        if (!parent.count(x)||!parent.count(y)){
            cout<<"unknown"<<endl;
            continue;
        }
        auto [ro1,re1]=find(x);
        auto [ro2,re2]=find(y);

        int ans=(re1+re2)%2;
        if (ro1!=ro2){
            cout<<"unknown"<<endl;
            
        }else if (ans==0){
            cout<<"parallel"<<endl;
        }else{
            cout<<"intersect"<<endl;
        }
    }

    
}
