#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>>adj(n+1,vector<int>());
    vector<int>dp(n+1,0);

    dp[n]=1;

    while (true){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        if (a==b&&a==0){
            break;
        }
        
    }


    for (int i=n-1;i>0;i--){
        for (auto u:adj[i]){
            dp[i]+=dp[u];
        }

    }
    cout<<dp[1];






    
}
