#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n,k;
    cin>>n>>k;
    long long r=0;
    vector<long long>v(n);

    for(int i=0;i<n;i++){
        cin>>v[i];
        r+=v[i];
    }

    long long l=*max_element(v.begin(),v.end());
    while (l<r){
        long long mid=l+(r-l)/2;
        long long cnt=1;
        long long cur=0;
        for (auto u:v){
            if (cur+u>mid){
                cnt++;
                cur=u;
            }else{
                cur+=u;
            }
            
        }

        if (cnt<=k){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    cout<<l;
    
}
