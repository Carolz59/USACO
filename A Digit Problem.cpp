#include<bits/stdc++.h>
using namespace std;

long long mod=1e9+7;
long long base=31;
long long mod1=1e9+9;
long long n;
string k;
long long full;
long long dp[1001][1<<10][2][2];

vector<long long>id(10,-1);


long long f(long long pos,long long mask,bool tight,bool state){
    if(pos==(long long)k.size()){
        if(mask==full&&state)
            return 1;

        if(!state&&id[0]!=-1&&full==(1<<id[0]))
            return 1;

        return 0;
    }

    if (dp[pos][mask][tight][state]!=-1){
        return dp[pos][mask][tight][state];
    }

    long long tot=0;
    long long lim;

    if (tight){
        lim=k[pos]-'0';
    }else{
        lim=9;
    }

    for (int i=0;i<=lim;i++){
        bool newt=(tight&&i==lim);
        bool news=state;
        long long nmask=mask;
        if (state||i!=0){
            news=true;
        }

        if (news&&id[i]!=-1){
            nmask|=(1<<id[i]);
        }

        tot=(tot+f(pos+1,nmask,newt,news)%mod+mod)%mod;

    }
    dp[pos][mask][tight][state]=tot;
    return tot;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    full=(1<<n)-1;
    memset(dp,-1,sizeof(dp));
    
    for (int i=0;i<n;i++){
        int x;
        cin>>x;
        id[x]=i;
    }
    cin>>k;
    if(k=="0"){
        if(id[0]!=-1){
            cout<<1;
        }else{
            cout<<0;
        }
        return 0;
    }
    cout<<f(0,0,1,0)<<endl;

}
