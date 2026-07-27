#include<bits/stdc++.h>
using namespace std;

int dp[300][300][300];
long long rec(int pie,int ppl,int least){
    if (pie==0){
        return ppl==0;
    }
    if (dp[pie][ppl][least]!=-1){
        return dp[pie][ppl][least];
    }

    long long ans=0;
    for (int i=least;i<=pie;i++){
        ans+=rec(pie-i,ppl-1,i);
    }
    dp[pie][ppl][least]=ans;
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,k;
    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    cout<<rec(n,k,1);


    
}
