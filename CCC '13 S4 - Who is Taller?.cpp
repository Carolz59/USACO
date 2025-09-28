#include<bits/stdc++.h>

using namespace std;

int n=100000;
vector<vector<int>>adj(n);
bool imtallerthanyoubitch(int x,int y){
    
    vector<bool>visited(n+1,false);
    vector<int>dist(n+1,0);
    queue<int>process;  
    visited[x]=true;
    process.push(x);
    dist[x]=0;

    while (!process.empty()){
        int cur=process.front();
        process.pop();

        for (int i=0;i<adj[cur].size();i++){
            int nei=adj[cur][i];
            if (visited[nei]==true){
                continue;
            }else{
                process.push(nei);
                dist[nei]=dist[cur]+1;
                visited[nei]=true;
                if (nei==y){
                    return true;
                    
                }
                
            }
        }
    }
    return false;

}

int main(){
    int peep,comp;
    int p,q;
    cin>>peep>>comp;
    int a,b;
    adj.assign(peep+1,{});
    
    for (int i=0;i<comp;i++){
        cin>>a>>b;
        adj[a].push_back(b);

    }
    cin>>p>>q;
    if (imtallerthanyoubitch(p,q)){
        cout<<"yes"<<endl;
    }else if(imtallerthanyoubitch(q,p)){
        cout<<"no"<<endl;
    }else{
        cout<<"unknown"<<endl;
    }




}
