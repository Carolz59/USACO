#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t,n,b;
    cin>>t>>n;
    
    
    vector<vector<pair<int,int>>>group(t+1,vector<pair<int,int>>());
    for (int i=0;i<n;i++){
        int c,v,ty;
        cin>>c>>v>>ty;
        group[ty].push_back({c,v});

    }
    
    cin>>b;
    vector<int>dp(b+1,INT_MIN);
    dp[0]=0;

    for (int i=1;i<=t;i++){
        vector<int>newdp(b+1,INT_MIN);
        for (auto [cost,val]:group[i]){
            for (int j=b;j>=cost;j--){
                if (dp[j-cost]!=INT_MIN){
                    newdp[j]=max(newdp[j],dp[j-cost]+val);
                }
            }
        }
        dp=newdp;
    }

    int ans=INT_MIN;

    for (int i=1;i<=b;i++){
        ans=max(dp[i],ans);
    }

    if (ans==INT_MIN){
        cout<<-1;
        return 0;
    }
    cout<<ans;



}
