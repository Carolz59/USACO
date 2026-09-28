#include<bits/stdc++.h>
using namespace std;

//000001111111
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cin>>n;
    long long p=((n*n)+1)/2;

    long long l=1;
    long long r=n*n;

    while (l<r){
        long long mid=l+(r-l)/2;
        long long cnt=0;
        long long i=1;
        for (int i=1;i<=n;i++){
            cnt+=min(n,mid/i);
        }

        if (cnt>=p){
            r=mid;
        }else{
            l=mid+1;
        }
    }

    cout<<l;
    
}
