#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,t;
    cin>>n>>t;

    vector<int>dp(t+1,0);

    for (int i=0;i<n;i++){
        int t1,t2,t3,p1,p2,p3;
        cin>>t1>>p1>>t2>>p2>>t3>>p3;

        for (int j=t;j>=0;j--){
            if (j>=t1){
                dp[j]=max(dp[j-t1]+p1,dp[j]);

            }
            if (j>=t2){
                dp[j]=max(dp[j-t2]+p2,dp[j]);

            }
            if (j>=t3){
                dp[j]=max(dp[j-t3]+p3,dp[j]);

            }
        }


    }

    cout<<dp[t];

    
    

}
