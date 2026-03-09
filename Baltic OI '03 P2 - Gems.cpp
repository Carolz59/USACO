#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>>adj,dp;
//dp[color][node]=cost
void dfs(int p,int c){
    for (int i=1;i<=3;i++){
        dp[i][c]=i;
    }

    for (auto child:adj[c]){
        if (child==p){
            continue;
        }

        dfs(c,child);
        for (int i=1;i<=3;i++){
            int best=INT_MAX;

            for (int j=1;j<=3;j++){
                if (i==j){
                    continue;
                }

                best=min(best,dp[j][child]);
            }
            dp[i][c]+=best;
        }
    }


}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;

    adj.assign(n+1,vector<int>());
    dp.assign(4,vector<int>(n+1,0));

    for (int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    dfs(0,1);

    int c1=dp[1][1];
    int c2=dp[2][1];
    int c3=dp[3][1];
    cout<<min({c1,c2,c3});




   

}
