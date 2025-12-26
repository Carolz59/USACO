#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("outofplace.in","r",stdin);
    freopen("outofplace.out","w",stdout);

    int n;
    vector<int>unsort,sorted;
    cin>>n;
    for (int i=0;i<n;i++){
        int h; cin>>h;
        unsort.push_back(h);
        sorted.push_back(h);

    }
    sort(sorted.begin(),sorted.end());
    int cnt=0;
    for (int i=0;i<n;i++){
        if (unsort[i]!=sorted[i]){
            cnt++;
        }
        
    }
    cout<<cnt-1;


}
