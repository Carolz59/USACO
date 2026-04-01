#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    
    vector<int>t;
    int tot=0;
    


    for (int i=1;i<=n;i++){
        int x;
        cin>>x;
        tot+=x;
        t.push_back(x);
        

    }
    vector<bool>dp(tot+1);
    dp[0]=true;
    for (auto u:t){
        for (int i=tot;i>=u;i--){
            if (dp[i-u]){
                dp[i]=true;
            }
        }
    }

    int ans=INT_MAX;
    for (int i=tot;i>=tot/2;i--){
        if (dp[i]){
                ans=min(ans,abs(tot-i-i));
            }
    }

    cout<<ans;
    
}
