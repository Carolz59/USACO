#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,m;
    cin>>n>>m;
    set<long long>s;

    for (int i=1;i<=n;i++){
        s.insert(i);
    }

    long long cnt=0;
    while (m--){
        long long x;
        cin>>x;
        auto it=s.upper_bound(x);
        if (it==s.begin()){
            break;
        }
        cnt++;
        it--;
        s.erase(it);
        
    }
    cout<<cnt;

    
    
}
