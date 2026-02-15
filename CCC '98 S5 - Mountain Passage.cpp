#include <bits/stdc++.h>
using namespace std;

int t,n;
vector<vector<int>>grid;
vector<vector<int>>dist;

int bfs(){
    deque<pair<int,int>>q;
    dist[1][1]=0;
    q.push_back({1,1});
    int cur=grid[1][1];
    int x[4]={1,-1,0,0};
    int y[4]={0,0,1,-1};
    while (!q.empty()){
        auto [r,c]=q.front();
        q.pop_front();
        for (int i=0;i<4;i++){
            int nr=r+y[i];
            int nc=c+x[i];
            if (nr>=1&&nr<=n&&nc>=1&&nc<=n&&abs(grid[nr][nc]-grid[r][c])<=2){
                int cost=0;
                if (grid[nr][nc]>cur||grid[r][c]>cur){
                    cost=1;
                }else{
                    cost=0;
                }
                if (dist[nr][nc]==-1||dist[nr][nc]>dist[r][c]+cost){
                    dist[nr][nc]=dist[r][c]+cost;
                    if (cost==0){
                        q.push_front({nr,nc});
                    }else{
                        q.push_back({nr,nc});
                    }
                    

                }
                
                
            }
        }

    }
    return dist[n][n];

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>t;

    for (int i=0;i<t;i++){
        cin>>n;
        grid.assign(n+1,vector<int>(n+1,0));
        dist.assign(n+1,vector<int>(n+1,-1));
        for (int s=1;s<=n;s++){
            for (int d=1;d<=n;d++){
                cin>>grid[s][d];
            }
        }

        int ans=bfs();

        if (ans==-1){
            cout<<"CANNOT MAKE THE TRIP";
            if (i!=t-1){
                cout<<"\n\n";
            }else{
                cout<<"\n";
            }
        }else{
            cout<<ans;
            if (i!=t-1){
                cout<<"\n\n";
            }else{
                cout<<"\n";
            }
        }
    }
    

    
}
