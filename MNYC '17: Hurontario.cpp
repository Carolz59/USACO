#include<bits/stdc++.h>
using namespace std;

string a,b;
long long mod=1e9+7;
long long base=31;
long long mod1=1e9+9;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>a>>b;

    long long x=(long long)a.size();
    long long y=(long long)b.size();
    long long p=1;
    long long cnt=1;
    long long cur1=0,cur2=0;
    long long lap=0;
    for (int i=1;i<=min(x,y);i++){
        cur1=((a[x-i]-'A'+1)*p+cur1%mod+mod)%mod;
        cur2=(cur2*base+(b[i-1]-'A'+1)%mod+mod)%mod;
        if (cur1==cur2){
            lap=max(lap,cnt);
        }
        p=p*base%mod;
        cnt++;
    }
    cout<<a;
    for (int i=lap;i<y;i++){
        cout<<b[i];
    }


} 
