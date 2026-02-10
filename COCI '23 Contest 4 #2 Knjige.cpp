#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n,t,a,b;
    cin>>n>>t>>a>>b;
    vector<long long>val(n);

    for (int i=0;i<n;i++){
        cin>>val[i];

    }
    sort(val.begin(),val.end());
    vector<long long>pref(n+1);
    pref[0]=0;
    for (int i=0;i<n;i++){
        pref[i+1]=pref[i]+val[i];
    }

    long long ans=0;

    for (int i=0;i<=n;i++){
        if (i*a>t){
            break;
        }
        long long k=min(n,i+(t-a*i)/b);

        if (k<i){
            continue;
        }
        long long cur=pref[k]-pref[k-i];

        

        ans=max(ans,cur);



    }

    cout<<ans;



    
    
}
