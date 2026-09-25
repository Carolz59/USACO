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
    sort(v.begin(),v.end());

    long long l=v[n/2];
    long long r=v[n/2]+k;
    long long mid;

    while (l<r){
        mid=l+(r-l+1)/2;
        long long need=0;
        for (long long i=n/2;i<n;i++){
            if (v[i]<mid){
                need+=mid-v[i];
            }

        }
        if (need<=k){
            l=mid;
        }else{
            r=mid-1;
        }
    }
    cout<<l;
    
}
