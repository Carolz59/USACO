#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    vector<int>v(3);
    vector<int>dp(n+1,INT_MIN);
    for (int i=0;i<3;i++){
        cin>>v[i];
        dp[v[i]]=1;
    }
    dp[0]=0;

    for (int i=1;i<=n;i++){
        for (int j=0;j<3;j++){
            if (i>v[j]&&dp[i-v[j]]!=INT_MIN){
                dp[i]=max(dp[i],dp[i-v[j]]+1);
                
            }
        }
    }

    cout<<dp[n];
   


}
