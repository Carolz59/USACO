#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    vector<int>h(n);

    for (int i=0;i<n;i++){
        cin>>h[i];
    }

    vector<int>ans(n+1,INT_MAX);
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    ans[1]=0;
    for (int len=2;len<=n;len++){
        for (int i=0;i+len-1<n;i++){
            int l=i;
            int r=i+len-1;

            if (len==2){
                ans[2]=min(ans[2],abs(h[l]-h[r]));
                dp[l][r]=abs(h[l]-h[r]);
            }else{
                if (dp[l+1][r-1]!=INT_MAX){
                    dp[l][r]=dp[l+1][r-1]+abs(h[l]-h[r]);
                }
                
                ans[len]=min(ans[len],dp[l][r]);
            }
        }
    }

    for (int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
}
