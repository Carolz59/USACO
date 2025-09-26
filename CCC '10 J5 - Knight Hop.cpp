#include<bits/stdc++.h>

using namespace std;

struct pt{
    int x,y,dist;
};

int s=8;



bool valid(int x,int y){
    if (x>=0&&x<8&&y>=0&&y<8){
        return true;
    }else{
        return false;
    }
}

int bfs(int sx,int sy,int fx,int fy){
    queue<pt>process;
    vector<vector<bool>>visited(8,vector<bool>(8,false));
    int dx[8] = {2,2,-2,-2,1,-1,1,-1};
    int dy[8] = {1,-1,1,-1,2,2,-2,-2};

    process.push({sx,sy,0});
    visited[sx][sy]=true;
    while (!process.empty()){
        pt cur=process.front();
        process.pop();

        //finish pt reached
        if (cur.x==fx&&cur.y==fy){
            return cur.dist;
            
        }
        for (int i=0;i<8;i++){
            int nx=cur.x+dx[i];
            int ny=cur.y+dy[i];
            if (valid(nx,ny)&&!visited[nx][ny]){
                visited[nx][ny]=true;
                process.push({nx,ny,(cur.dist+1)});
            }
        }

    }
    return -1;//ts never happening gng
    

}

    
int main(){
    int sx,sy,fx,fy;
    cin>>sx>>sy>>fx>>fy;
    sx--;
    sy--;
    fx--;
    fy--;
    cout<<bfs(sx,sy,fx,fy);
    return 0;

}
