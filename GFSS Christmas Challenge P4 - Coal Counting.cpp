#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    vector<int>kid(n);
    for (int i=0;i<n;i++){
        cin>>kid[i];

    }

    sort(kid.begin(),kid.end());
    vector<int>ans;

    for (int i=0;i<m;i++){
        int t;
        cin>>t;
        auto it=lower_bound(kid.begin(),kid.end(),t);
        ans.push_back(it-kid.begin());
    }

    for (auto u:ans){
        cout<<(n-u)<<endl;
    }

    


}
