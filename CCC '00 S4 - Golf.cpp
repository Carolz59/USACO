#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long d,n;
    cin>>d>>n;
    vector<long long>weight(n+1,0);

    for (int i=1;i<n+1;i++){
        cin>>weight[i];

    }

    vector<long long>dp(d+1,LLONG_MAX);
    dp[0]=0;

    for (long long i=1;i<=d;i++){
        for (int j=1;j<n+1;j++){
            if (i>=weight[j]&&dp[i-weight[j]]!=LLONG_MAX){
                dp[i]=min(dp[i],dp[i-weight[j]]+1);
                
            }
        }
    }

    if (dp[d]==LLONG_MAX){
        cout<<"Roberta acknowledges defeat.";
        return 0;
    }
    cout<<"Roberta wins in "<<dp[d]<<" strokes.";






}
