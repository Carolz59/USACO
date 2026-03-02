#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    set<string>dict;

    for (int i=0;i<n;i++){
        string z;
        cin>>z;
        dict.insert(z);
    }

    int w;
    cin>>w;

    for (int i=0;i<w;i++){
        string s;
        cin>>s;

        vector<int>dp(s.size()+1,INT_MAX);
        vector<int>recon(s.size()+1,-1);
        dp[0]=0;
        for (int x=1;x<=s.size();x++){
            for (int j=max(0,x-20);j<=x-1;j++){
                string newword=s.substr(j,x-j);
                if (dict.count(newword)&&dp[j]!=INT_MAX){
                    if (dp[j]+1<dp[x]){
                        dp[x]=dp[j]+1;
                        recon[x]=j;
                    }
                    
                }
                

            }
        }
        int ans=dp[s.size()];
        if (ans==INT_MAX){
            cout<<"***"<<s<<endl;
            continue;
        }
        int cur=s.size();
        vector<string>words;

        while (cur>0){
            int start=recon[cur];
            if (start==-1){
                break;
            }
            words.push_back(s.substr(start,cur-start));
            cur=start;
        }
        for (int k=words.size()-1;k>=0;k--){
            cout<<words[k];
            if (k!=0){
                cout<<" ";
            }
        }
        cout<<endl;

        
    }

    

    

    
}
