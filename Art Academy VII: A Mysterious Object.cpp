#include<bits/stdc++.h>
using namespace std;

long long mod=1e9+7;
//long long base=31;
//long long mod1=1e9+9;
string s;
vector<vector<vector<long long>>>dp;
long long nah(long long pos,long long tight,long long state){
    if (pos==s.size()&&state==2){
        return 1;

    }
    if (pos==s.size()&&state!=2){
        return 0;
    }

    if (dp[pos][tight][state]!=-1){
        return dp[pos][tight][state];
    }
    long long tot=0;

    long long lim;
    if (tight==1){
        lim=s[pos]-'0';
    }else{
        lim=9;
    }

    for (int i=0;i<=lim;i++){
        int news=state;
        if (state==0){
            if (i==1){
                news=1;

            }
        }else if (state==1){
            if (i==0){
                news=2;
            }
        }else if (state==2){
            if (i==0){
                news=3;
            }
        }

        tot=(tot+nah(pos+1,i==lim&&(tight),news)%mod+mod)%mod;
        
    }
    dp[pos][tight][state]=tot;
    return tot;


}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>s;
    dp.assign(s.size(),vector<vector<long long>>(2,vector<long long>(4,-1)));
    cout<<nah(0,1,0);
    
}
