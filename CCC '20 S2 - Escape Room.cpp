#include<bits/stdc++.h>

using namespace std;

bool amimentallystable=false;

bool bfs(int x,int y, const vector<vector<int>>&grid){
    vector<vector<bool>>visited(y+1,vector<bool>(x+1,false));
    queue<pair<int,int>>q;

    q.push({1,1});
    visited[1][1]=true;

    while (!q.empty()){
        auto cur=q.front();
        q.pop();

        int num=grid[cur.first][cur.second];

        if (cur.first==y&&cur.second==x) {
            return true; // get out bro
        }

        for (int i=1;i*i<=num;i++){//find the factor
            if(num%i==0){
                int j=num/i;

                if (i<=y&&j<=x&&!visited[i][j]){
                    q.push({i,j});
                    visited[i][j]=true;
                }

                if (i<=x&&j<=y&&!visited[j][i]){
                    q.push({j,i});
                    visited[j][i]=true;
                }
                

            }

        }


        
        
    }
    return false;



}

int main(){

    int x,y;
    cin>>y>>x;

    vector<vector<int>> grid(y+1,vector<int>(x+1));

    for (int i=1;i<=y;i++){
        for (int j=1;j<=x;j++){
            cin>>grid[i][j];
        }
    }
    if(bfs(x,y,grid)==false){
        cout<<"no"<<endl;
    }else{
        cout<<"yes"<<endl;
    }

}
