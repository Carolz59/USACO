#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,c;
    cin>>n>>c;

    vector<pair<long long,long long>>val(n);
    for (int i=0;i<n;i++){
        long long x,y;
        cin>>x>>y;
        val[i]={x,y};

    }

    vector<long long>dp(c+1,LLONG_MIN);
    dp[0]=0;

    for (int i=0;i<n;i++){
        auto [w,v]=val[i];
        for (int j=c;j>=w;j--){
            if (j>=w&&dp[j-w]!=LLONG_MIN){
                dp[j]=max(dp[j],dp[j-w]+v);
            }

        }
    }
    long long ans=0;
    for (int i=c;i>=0;i--){
        if (dp[i]!=LLONG_MIN){
            ans=max(ans,dp[i]);
        }
    }
    cout<<ans;
    
}
