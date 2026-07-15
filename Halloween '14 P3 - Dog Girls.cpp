#include<bits/stdc++.h>
using namespace std;

string s;
long long mod=1000000007;
long long base=31;
vector<long long>power,haha;

long long hashify(long long x,long long y){
    return (haha[y+1]-haha[x]*power[y-x+1]%mod+mod)%mod;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>s;
    long long n=(long long)s.size();
    power.assign(n+1,1);
    haha.assign(n+1,0);
    unordered_set<long long>unique;
    for (int i=1;i<=n;i++){
        power[i]=(power[i-1]*base)%mod;
    }
    for (int i=0;i<n;i++){
        haha[i+1]=(haha[i]*base+s[i])%mod;
    }

    for (int i=0;i<n;i++){
        long long tot=n-i;
        for (int j=1;j*2<=tot;j++){
            long long x=hashify(i,i+j-1);
            if (unique.find(x)!=unique.end()){
                continue;
            }
            for (int z=j;z+j<=tot;z+=j){
                long long y=hashify(i+z,i+z+j-1);
                if (y==x){
                    unique.insert(hashify(i,i+z+j-1));
                }else{
                    break;
                }
            }
        }
    }

    cout<<unique.size();




}
