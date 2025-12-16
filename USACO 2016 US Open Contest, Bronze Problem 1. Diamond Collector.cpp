#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {\
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);


    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for (int i=0;i<n;i++){
        cin>>v[i];

    }
    sort(v.begin(),v.end());
    int ma=1;
    for (int i=0;i<n;i++){
        int cnt=0;
        for (int j=i;j<n;j++){
            if (abs(v[i]-v[j])<=k){
                cnt++;
            }
        }
        if (cnt>ma){
            ma=cnt;
        }
    }
    cout<<ma<<endl;
}
