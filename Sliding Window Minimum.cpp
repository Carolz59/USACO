#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,k,x,a,b,c;
    cin>>n>>k>>x>>a>>b>>c;
    deque<pair<int,long long>>dik;
    long long ans=0;

    dik.push_front({0,x});
    for (int i=0;i<n;i++){
        if (i>0){
            x=((x*a)+b)%c;
        }
        
        while (!dik.empty()&&dik.back().second>=x){
            dik.pop_back();
        }
        while (!dik.empty()&&dik.front().first<=i-k){
            dik.pop_front();
        }
        dik.push_back({i,x});
        if (i>=k-1){
            ans^=dik.front().second;

        }
    }
    cout<<ans;
    
}
