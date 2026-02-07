#include <bits/stdc++.h>
using namespace std;

//5 1 4
//6 2 4

//1 4 5
//2 4 6
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t,n;
    cin>>t>>n;
    vector<int>v1,v2;
    for (int i=0;i<n;i++){
        int x;
        cin>>x;
        v1.push_back(x);

    }
    for (int i=0;i<n;i++){
        int x;
        cin>>x;
        v2.push_back(x);

    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());

    int ans=0;
    if (t==2){
        for (int i=0;i<n;i++){
            ans+=max(v1[i],v2[n-1-i]);
        }
        cout<<ans<<endl;
        return 0;
    }else{
        for (int i=0;i<n;i++){
            ans+=max(v1[i],v2[i]);
        }
        cout<<ans<<endl;
        return 0;

    }
}
