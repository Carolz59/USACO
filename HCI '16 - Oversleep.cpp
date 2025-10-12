#include<bits/stdc++.h>

using namespace std;

int r,c;

vector<string>grid;


int xmove[4]={1,-1,0,0};
int ymove[4]={0,0,1,-1};

int onedee(int row,int col){
    return row*c+col;

}

int bfs(pair<int,int>&start,pair<int,int>&end){
    deque<pair<int,int>>q;
    vector<int>dist(r*c,1000000);
    q.push_back({start.first,start.second});
    dist[onedee(start.first,start.second)]=0;

    while(!q.empty()){
        auto cur=q.front();
        q.pop_front();
        int curdist=dist[onedee(cur.first, cur.second)];


        if (cur.first==end.first&&cur.second==end.second){
            return curdist;

        }

        for (int i=0;i<4;i++){
            int newx=cur.second+xmove[i];
            int newy=cur.first+ymove[i];

            if(newx>=0&&newy>=0&&newx<c&&newy<r){
                char step=grid[newy][newx];
                if (step=='X'){
                    continue;
                }
                int weight=(step=='e'?0:1);
                int newid=onedee(newy,newx);
                if (dist[newid]>(curdist+weight)){
                    dist[newid]=curdist+weight;
                    if (weight==0){
                        q.push_front({newy,newx});
                    }else{
                        q.push_back({newy,newx});
                    }
                }
            }


        }


    }
    return -1;

}

int main(){
    cin>>r>>c;
    grid.resize(r);

    for (int i=0;i<r;i++){
        cin>>grid[i];
    }
    pair<int,int> s,e;

    for (int i=0;i<r;i++){
        for (int j=0;j<c;j++){
            if (grid[i][j]=='s'){
                s={i,j};
            }
            if (grid[i][j]=='e'){
                e={i,j};
            }
        }
    }

    cout<<bfs(s,e)<<endl;
    cout<<endl;
    return 0;
}
