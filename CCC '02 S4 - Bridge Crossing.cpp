#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m,p;
    cin>>m>>p;
    vector<int>t(p+1);
    vector<string>n(p+1);

    for (int i=1;i<p+1;i++){
        cin>>n[i]>>t[i];

    }

    vector<int>dp(p+1,INT_MAX);
    vector<int>g(p+1,0);

    dp[0]=0;


    for (int i=1;i<=p;i++){
        int maxtime=0;
        for (int j=0;j<m&&i-j>0;j++){
            
            maxtime=max(maxtime,t[i-j]);
            if (dp[i]>maxtime+dp[i-j-1]){
                dp[i]=maxtime+dp[i-j-1];
                g[i]=j+1;
            }
        }

}
    int i=p;
    vector<vector<string>>q;

    cout<<"Total Time: "<<dp[p]<<endl;

    
    while(i>0){
        vector<string>seq;
        for (int j=i-g[i]+1;j<=i;j++){
            seq.push_back(n[j]);
            
            
        }
        i=i-g[i];
        q.push_back(seq);

        
    }

    reverse(q.rbegin(),q.rend());

    for (auto u:q){
        for (auto v:u){
            cout<<v<<" ";
        }
        cout<<endl;
    }





}
