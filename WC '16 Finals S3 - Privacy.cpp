#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin>>n>>k;

    vector<int>req(n+1);

    for (int i=1;i<=n;i++){
        cin>>req[i];
    }

    vector<vector<int>>dp(n+1,vector<int>(k+2,INT_MAX));
    vector<vector<int>>cost(n+1,vector<int>(n+1));

    for (int l=1;l<=n;l++){
        for (int r=l;r<=n;r++){
            int tot=0;
            int leng=r-l;
            for (int i=l;i<=r;i++){
                if (leng>req[i]){
                    tot+=leng-req[i];
                }

            }
            cost[l][r]=tot;
        }
    }

    dp[0][0]=0;//dp[i][j]=x(i cows,j seg=x bribes min)
    for (int i=1;i<=n;i++){
        for (int j=1;j<=k+1;j++){
            for (int e=0;e<i;e++){
                if (dp[e][j-1]!=INT_MAX){
                    dp[i][j]=min(dp[i][j],dp[e][j-1]+cost[e+1][i]);
                }
            }
        }
    }

    cout<<dp[n][k+1];

}
