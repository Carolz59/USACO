#include<bits/stdc++.h>

using namespace std;

struct pt{
    int x,y,d;

};
int n=5000;

int xmove[4]={1,-1,0,0};
int ymove[4]={0,0,1,-1};

vector<string> grid(n);

int bfs(pair<int,int> start, pair<int,int> goal, int l, int w){
    queue<pt>q;
    vector<vector<int>> dist(l,vector<int>(w,-1));
    q.push({start.first,start.second,0});
    dist[start.first][start.second]=0;
    

    while(!q.empty()){
        pt cur=q.front();
        q.pop();
        if (cur.d>=60){ // not worth
            return -1; 
        }

        if (cur.x==goal.first&&cur.y==goal.second){ // found ur target
            return cur.d; 
        }
        

        for (int i=0;i<4;i++){
            int newx=cur.x+xmove[i];
            int newy=cur.y+ymove[i];

            if (newx>=0&&newx<l&&newy>=0&&newy<w&&grid[newx][newy]!='X'&&dist[newx][newy]==-1){
                q.push({newx,newy,cur.d+1});
                dist[newx][newy] = cur.d + 1;
            }

        }
    }
    return -1; //shouldnt get here...

}




int main(){

    int tot,l,w;
    string s;
    cin>>tot;
    vector<string>results;
    for (int i=0;i<tot;i++){
        pair<int,int> start, goal;
        cin>>l>>w;
        grid.assign(w, "");
        if (w==0){
            cout<<"#notworth"<<endl;
            break;
        }
        for (int j=0;j<w;j++){
            cin >> grid[j];
            for (int o=0;o<l;o++){
                if (grid[j][o]=='C'){
                    start={j,o};
                }
                if (grid[j][o]=='W'){
                    goal={j,o};
                }
            }
            
        }
        int steps = bfs(start,goal,w,l);
        if (steps==-1){
            results.push_back("#notworth");
            
        }else{
            results.push_back(to_string(steps));
        }

    }
    for (auto&u:results){
        cout<<u<<endl;
    }
    return 0;

}
