#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
//    freopen("moocrypt.in", "r", stdin);
//    freopen("moocrypt.out", "w", stdout); 

    int l;
    string dir;
    int n;
    cin>>l;
    vector<pair<int,int>>v;

    for (int i=0;i<l;i++){
        cin>>dir>>n;
        if (dir=="G") v.push_back({n,-1});
        else v.push_back({n,1});

    }
    
    int ma=l;
    sort(v.begin(),v.end());
    for (int i=0;i<l;i++){
        int liar=0;
        for (int left=0;left<i;left++){
            if (v[left].second==1){
                liar++;
            }
        }
        for (int right=i+1;right<l;right++){
            if (v[right].second==-1){
                liar++;
            }
        }
        ma=min(ma,liar);
    }
    cout<<ma;

}
