#include <bits/stdc++.h>
using namespace std;

int z,n,m;

vector<vector<int>>grid;
vector<vector<bool>>visited;

int bfs(){
    int x[4]={1,-1,0,0};
    int y[4]={0,0,1,-1};

    visited.assign(n,vector<bool>(m,false));

    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>q;
    for (int i=0;i<n;i++){
        q.push({grid[i][0],i,0});
        q.push({grid[i][m-1],i,m-1});
        visited[i][0]=true;
        visited[i][m-1]=true;

    }

    for (int i=1;i<m;i++){
        q.push({grid[0][i],0,i});
        q.push({grid[n-1][i],n-1,i});
        visited[0][i]=true;
        visited[n-1][i]=true;

    }

    int water=0;
    while (!q.empty()){
        auto [h,r,c]=q.top();
        q.pop();

        for (int i=0;i<4;i++){
            int tempr=r+x[i];
            int tempc=c+y[i];
            if (tempr>=n||tempr<0||tempc>=m||tempc<0){
                continue;
            }
            if (visited[tempr][tempc]){
                continue;
            }
            visited[tempr][tempc]=true;
            
            if (grid[tempr][tempc]<h){
                water+=h-grid[tempr][tempc];
            }
            q.push({max(h,grid[tempr][tempc]),tempr,tempc});


        }
    }
    return water;

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>z;
    vector<int>ans;
    

    for (int k=0;k<z;k++){
        cin>>n>>m;
        grid.assign(n,vector<int>(m));
        

        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                cin>>grid[i][j];
            }
        }

        ans.push_back(bfs());


    }

    for (auto u:ans){
        cout<<u<<endl;
    }




    
    
}
