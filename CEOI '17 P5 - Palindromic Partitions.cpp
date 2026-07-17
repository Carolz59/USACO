#include<bits/stdc++.h>
using namespace std;

long long t;
long long mod=1e9+7;
long long base=31;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    
    while (t--){
        string s;
        cin>>s;
        long long ans=0;
        long long l=0,r=s.size()-1;
        long long curl=0,curr=0;
        long long power=1;
        while (r>l){
            curl=(curl*base+(s[l]-'a'+1))%mod;
            curr=(curr+(s[r]-'a'+1)*power)%mod;
            power=(base*power)%mod;
            if (curl==curr){
                ans+=2;
                curl=0;
                curr=0;
                power=1;

            }
            l++;
            r--;

        }
        if (l==r||curl!=0){
            ans++;
        }
        cout<<ans<<endl;


        
    }
    



    
}
