#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a,b;
    cin>>a>>b;

    int n=int(a.size());
    int m=int(b.size());

    vector<vector<int>>dp(n+1,vector<int>(m+1,INT_MIN));
    dp[0][0]=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (a[i-1]==b[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;

            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }

    }

    string res="";
    while (n>0&&m>0){
        if (a[n-1]==b[m-1]){
            res+=a[n-1];
            n--;
            m--;
        }else if(dp[n][m-1]>dp[n-1][m]){
            m--;
        }else{
            n--;
        }
    }

    reverse(res.begin(),res.end());
    cout<<res;
    
    
}
