#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int sets=5;
    while (sets--){
        int tot,n;
        cin>>tot>>n;
        set<int>val;
        vector<int>dp(tot+1,INT_MAX);
        for (int i=0;i<n;i++){
            int v;
            cin>>v;
            val.insert(v);
            dp[v]=1;
        }
        dp[0]=0;

        for (int i=1;i<=tot;i++){
            for (auto j:val){
                if (i<j||dp[i-j]==INT_MAX){
                    continue;
                }
                dp[i]=min(dp[i],dp[i-j]+1);
            }
        }

        cout<<dp[tot]<<endl;

    }



}
