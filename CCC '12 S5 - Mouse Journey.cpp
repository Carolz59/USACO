#include <bits/stdc++.h>
using namespace std;
//right,down
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int r,c;
    cin>>r>>c;
    vector<vector<int>>grid(r+1,vector<int>(c+1,-1));
    vector<vector<int>>dp(r+1,vector<int>(c+1,0));
    int k;
    cin>>k;
    for (int i=0;i<k;i++){
        int a,b;
        cin>>a>>b;
        grid[a][b]=1;
        
    }
    dp[1][1]=1;

    for (int i=1;i<=r;i++){
        for (int j=1;j<=c;j++){
            if (grid[i][j]==1){
                dp[i][j]=0;
            }else{
                if (i>1){
                    dp[i][j]+=dp[i-1][j];
                }
                if (j>1){
                    dp[i][j]+=dp[i][j-1];
                }
            }
        }
    }

    cout<<dp[r][c];

}
