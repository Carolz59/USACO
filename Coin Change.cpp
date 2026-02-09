#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,d;
    cin>>n>>d;
    vector<int>val;
    vector<int>dp(n+1,INT_MAX);
    dp[0]=0;
    for (int i=0;i<d;i++){
        int c;
        cin>>c;
        val.push_back(c);
        dp[c]=1;
        

    }

    
//dp[n]=min coints to fulfill n dols
    for (int i=1;i<=n;i++){
        for (int j=0;j<val.size();j++){
            if (i>=val[j]&&dp[i-val[j]]!=INT_MAX){
                dp[i]=min(dp[i],dp[i-val[j]]+1);
                

            }
        }
    }
    cout<<dp[n];

    
    
}
