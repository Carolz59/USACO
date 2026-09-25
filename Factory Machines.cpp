#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,t;
    cin>>n>>t;
    vector<long long>v(n);
    for (int i=0;i<n;i++){
        cin>>v[i];
    }

    long long l=1;
    long long r=*min_element(v.begin(),v.end())*t;
    while (l<r){
        long long mid=l+(r-l)/2;
        long long tot=0;
        for (auto u:v){
            tot+=mid/u;
        }

        if (tot>=t){
            r=mid;
        }else{
            l=mid+1;
        }


    }
    cout<<l;
    
}
