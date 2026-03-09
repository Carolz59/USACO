#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<vector<int>>grid(n,vector<int>());

    for (int i=0;i<n;i++){
        for (int j=0;j<=i;j++){
            int v;
            cin>>v;
            grid[i].push_back(v);
        }
    }

    vector<vector<int>>dp=grid;

    for (int i=n-2;i>=0;i--){
        for (int j=0;j<=i;j++){
            dp[i][j]=max(dp[i+1][j]+grid[i][j],dp[i+1][j+1]+grid[i][j]);
        }
    }

    cout<<dp[0][0];

}
