#include <bits/stdc++.h>
using namespace std;

map<int,int>adj;
map<int,int>state;
map<int,int>cycle;
map<int,int>pos;
map<int,int>siz;

int cid=0;

void findcycle(int s){
    map<int,int>idx;
    int cur=s;
    int steps=0;

    while (state[cur]==0){
        idx[cur]=steps;
        steps++;
        state[cur]=1;
        cur=adj[cur];

    }

    if (state[cur]==1){
        int start=idx[cur];
        int sz=steps-start;

        int x=cur;

        for (int i=0;i<sz;i++){
            pos[x]=i;
            cycle[x]=cid;
            x=adj[x];
        }
        siz[cid]=sz;
        cid++;

    }
    while (state[s]==1){
        state[s]=2;
        s=idx[s];
    }


}



int main() {
    int n;
    cin>>n;

    for (int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        adj[a]=b;
        state[a]=0;
        cycle[a]=-1;
        pos[a]=-1;
    }

    for (auto i:adj){
        if (state[i.first]==0){
            findcycle(i.first);
        }
    }

    while (true){
        int a,b;
        cin>>a>>b;

        if (a==b&&a==0){
            break;

        }
        if (cycle[a]!=cycle[b]){
            cout<<"No"<<endl;;
        }else{
            cout<<"Yes"<<" ";
            int n=adj[a];
            int cnt=0;

            while (true){
                
                if (n==b){
                    break;
                }
                n=adj[n];
                cnt++;
            }
            cout<<cnt<<endl;
        }


    }


}
