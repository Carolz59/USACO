#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<int>a(n+1);
    vector<int>b(n+1);

    for (int i=1;i<=n;i++){
        cin>>a[i];
    }

    for (int i=1;i<=n;i++){
        cin>>b[i];
    }

    vector<vector<long long>>dp(n+1,vector<long long>(3,-1000000));

    dp[0][0]=0;

    for (int i=1;i<=n;i++){

        dp[i][0]=max({dp[i-1][0]+b[i],dp[i-1][1]+b[i],dp[i-1][2]+b[i]});
        dp[i][1]=dp[i-1][0]+a[i];
        dp[i][2]=dp[i-1][1]+a[i];
        
    }

    cout<<max({dp[n][0],dp[n][1],dp[n][2]});

}
