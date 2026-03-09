#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    vector<vector<int>>grid(n+1,vector<int>(m+1,0));
    vector<vector<int>>dp(n+1,vector<int>(m+1,INT_MAX));
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin>>grid[i][j];
        }
    }
    dp[1][1]=grid[1][1];

    for (int i=2;i<=m;i++){
        dp[1][i]=dp[1][i-1]+grid[1][i];
    }
    for (int i=2;i<=n;i++){
        dp[i][1]=dp[i-1][1]+grid[i][1];
    }

    for (int i=2;i<=n;i++){
        for (int j=2;j<=m;j++){
            dp[i][j]=min(dp[i-1][j]+grid[i][j],dp[i][j-1]+grid[i][j]);
        }
    }

    cout<<dp[n][m];
}
