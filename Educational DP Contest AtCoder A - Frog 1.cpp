#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;

    vector<long long>val(n,0),dp(n,INT_MAX);

    for (int i=0;i<n;i++){
        cin>>val[i];
    }

    dp[0]=0;
    dp[1]=abs(val[1]-val[0]);

    for (int i=2;i<n;i++){
        dp[i]=min(min(dp[i],dp[i-1]+abs(val[i]-val[i-1])),dp[i-2]+abs(val[i]-val[i-2]));
        
        
    }

    cout<<dp[n-1];
    


    
}
