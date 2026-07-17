#include<bits/stdc++.h>
using namespace std;

long long t;
long long mod=1e9+7;
long long base=31;
long long mod1=1e9+9;


string a,b;
vector<long long>power,pref,power1,pref1;

pair<long long,long long> hashify(long long x,long long y){
    long long h1=((pref[y]-pref[x]*power[y-x]%mod+mod)%mod);
    long long h2=((pref1[y]-pref1[x]*power1[y-x]%mod1+mod1)%mod1);
    return {h1,h2};
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>a>>b;
    if(a.size()>b.size()){
        cout<<0;
        return 0;
    }
    power.resize(b.size()+1);
    power[0]=1;
    pref.resize(b.size()+1);
    power1.resize(b.size()+1);
    power1[0]=1;
    pref1.resize(b.size()+1);

    for (int i=1;i<=b.size();i++){
        power[i]=power[i-1]*base%mod;
        power1[i]=power1[i-1]*base%mod1;
    }
    for (int i=1;i<=b.size();i++){
        pref[i]=(pref[i-1]*base+(b[i-1]-'a'+1))%mod;
        pref1[i]=(pref1[i-1]*base+(b[i-1]-'a'+1))%mod1;
    }

    long long l=0;
    long long r=a.size()-1;

    vector<long long>freq(27,0),comp(27,0);

    for (int i=0;i<a.size();i++){
        freq[a[i]-'a'+1]++;
        comp[b[i]-'a'+1]++;
    }
    
    set<pair<long long,long long>>unique;
    while (r<b.size()){
        if (freq==comp){
            unique.insert(hashify(l,r+1));
        }
        
        if (r<b.size()-1){
            comp[b[l]-'a'+1]--;
            comp[b[r+1]-'a'+1]++;
        }
        r++;
        l++;
        
    }

    cout<<unique.size();
    





}
