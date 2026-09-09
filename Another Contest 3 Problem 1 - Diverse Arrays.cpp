#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,k;
    cin>>n>>k;
    vector<long long>v(n);

    for (int i=0;i<n;i++){
        cin>>v[i];
    }

    long long l=0;
    vector<long long>m(n+1,0);
    long long cnt=0;
    long long ans=0;

    for (int r=0;r<n;r++){
        m[v[r]]++;
        if (m[v[r]]==1){
            cnt++;
            
        }
        while (cnt>=k){
            ans+=n-r;
            m[v[l]]--;
            if (m[v[l]]==0){
                cnt--;
            }
            l++;
        }
    }
    cout<<ans<<endl;
    
    
}
