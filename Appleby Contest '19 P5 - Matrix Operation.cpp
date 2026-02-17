#include <bits/stdc++.h>
using namespace std;

long long n;
vector<vector<long long>>dist;
vector<vector<long long>>grid;
vector<vector<long long>>dp;
long long dfs(long long r,long long c){
    if (dp[r][c]!=-1){
        return dp[r][c];
    }
    long long res=1;
    vector<pair<long long,long long>> dir={{1,0},{-1,0},{0,1},{0,-1}};

    for (auto [a,b]:dir){
        long long newr=r+a;
        long long newc=c+b;
        if(newc>0&&newc<=n&&newr>0&&newr<=n&&grid[newr][newc]>grid[r][c]){
            res=max(res,dfs(newr,newc)+1);

        }
    }
    dp[r][c]=res;
    return res;
    

    
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    
    grid.assign(n+1,vector<long long>(n+1));
    dp.assign(n+1,vector<long long>(n+1,-1));

    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin>>grid[i][j];
        }
    }

    long long ans=0;
    for (long long i=1;i<=n;i++){
        for (long long j=1;j<=n;j++){
            ans=max(dfs(i,j),ans);
        }
    }

    cout<<ans-1;


}
