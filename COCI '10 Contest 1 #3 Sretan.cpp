#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long k;
    cin>>k;

    int digits=1;
    int cnt=2;
    while (cnt<k){
        k-=cnt;
        cnt*=2;
        digits++;

    }

    k--;

    vector<int>v(digits);
    for (int i=digits-1;i>=0;i--){
        int rem=k%2;
        if (rem==0){
            v[i]=4;
        }else{
            v[i]=7;
        }
        k/=2;
    }

    for (auto u:v){
        cout<<u;
    }
    


    
}
