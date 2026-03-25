#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int d,i,r;
    cin>>d>>i>>r;
    string a,b;
    cin>>a>>b;
    int x=a.size();
    int y=b.size();
    vector<vector<int>>dp(x+1,vector<int>(y+1,1000000));

    for (int j=0;j<=x;j++){
        dp[j][0]=j*d;
    }
    for (int j=0;j<=y;j++){
        dp[0][j]=j*i;
    }

    for (int n=1;n<=x;n++){
        for (int m=1;m<=y;m++){
            if (a[n-1]==b[m-1]){
                dp[n][m]=dp[n-1][m-1];
                continue;
            }
            dp[n][m]=min({dp[n-1][m]+d,dp[n][m-1]+i,dp[n-1][m-1]+r});
        }
    }
    cout<<dp[x][y];





}
