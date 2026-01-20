#include <bits/stdc++.h>
using namespace std;


int n,m;
unordered_map<int,queue<pair<int,int>>>valtopos;
vector<vector<bool>>visited;

bool find(){
    queue<pair<int,int>>q;
    q.push({n,m});
    visited[n][m]=true;

    while (!q.empty()){
        auto cur=q.front();
        int f=cur.first;
        int s=cur.second;
        if (f==1&&s==1){
            return true;
        }
        q.pop();
        int target=f*s;
        if(valtopos.count(target)){
            while(!valtopos[target].empty()){
                auto loc=valtopos[target].front();
                if (!visited[loc.first][loc.second]){
                    q.push({loc.first,loc.second});
                    visited[loc.first][loc.second]=true;
                    valtopos[target].pop();
                }else{
                    valtopos[target].pop();
                }
            }
            valtopos.erase(target);



        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    visited.assign(n+1,vector<bool>(m+1,false));

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            int x;
            cin>>x;
            valtopos[x].push({i+1,j+1});
        }
    }

    if(find()){
        cout<<"yes";
    }else{
        cout<<"no";
    }





}
