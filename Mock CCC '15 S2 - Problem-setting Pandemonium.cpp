#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    
    map<int,int>m;
    int ans=0;
    for (int i=0;i<n;i++){
        int x;
        cin>>x;
        m[x]++;
    }

    for (auto [d,f]:m){
        ans=max(ans,f);
    }
    cout<<ans<<endl;
}
