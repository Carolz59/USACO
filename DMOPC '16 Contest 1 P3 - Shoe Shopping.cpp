#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<long double>val(n+1);
    vector<long double>dp(n+1,LLONG_MIN);

    for (int i=0;i<n;i++){
        cin>>val[i+1];
    }

    dp[0]=0;
    dp[1]=val[1];
    dp[2]=max(val[1],val[2])+(min(val[1],val[2])/2);
    
    for (int i=3;i<=n;i++){
        long double solo=val[i]+dp[i-1];
        long double doub=dp[i-2]+(min(val[i],val[i-1])/2)+max(val[i],val[i-1]);
        long double trip=dp[i-3]+val[i]+val[i-1]+val[i-2]-min({val[i],val[i-1],val[i-2]});
        dp[i]=min({solo,doub,trip});

    }

    cout<<fixed<<setprecision(1)<<dp[n];
    
}
