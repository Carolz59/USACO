#include <bits/stdc++.h>
using namespace std;

int t,n;

map<string,vector<string>>m;
pair<string,int> bfs(string s,map<string,vector<string>>&m){
    map<string,int>dist;
    queue<string>q;
    dist[s]=0;
    q.push(s);
    string targ=s;

    while (!q.empty()){
        string cur=q.front();
        q.pop();

        for (auto u:m[cur]){
            if (dist.find(u)==dist.end()){
                dist[u]=dist[cur]+1;
                q.push(u);
                if (dist[u]>dist[targ]){
                    targ=u;
                }
            }
        }

    }
    return make_pair(targ,dist[targ]);

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>t;
    string bfsstart;

    for (int i=0;i<t;i++){
        cin>>n;
        vector<string>names;
        m.clear();
        
        string root;
        for (int j=0;j<n;j++){
            string name;
            cin>>name;
            names.push_back(name);

        }

        
        root=names.back();
        m[root].push_back(names.front());
        bfsstart=root;

        for (auto u:names){
            m[root].push_back(u);
            root=u;
        }
        auto[n1,d1]=bfs(bfsstart,m);
        cout<<n*10-((d1*2)*10)<<endl;

        
    }

    
    
    
}
