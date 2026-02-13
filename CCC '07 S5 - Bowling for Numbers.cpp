#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin>>q;
    int n,b,w;

    for (int z=0;z<q;z++){
        cin>>n>>b>>w;
        vector<int>pins(n+1,0);
        vector<int>pref(n+1,0);
        vector<vector<int>>dp(n+1,vector<int>(b+1,0));

        for (int i=1;i<=n;i++){
            cin>>pins[i];
            pref[i]=pref[i-1]+pins[i];
        }

        for (int i=1;i<=b;i++){
            for (int j=1;j<=n;j++){
                int skip=dp[j-1][i];
                int news=0;

                if (j>=w){
                    int seg=pref[j]-pref[j-w];
                    news=seg+dp[j-w][i-1];
                }
                dp[j][i]=max(skip,news);
            }
        }

        cout<<dp[n][b]<<endl;


    
}

}
