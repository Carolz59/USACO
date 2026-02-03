#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    vector<int>v(n);

    for (int i=0;i<n;i++){
        cin>>v[i];
    }

    int l=0;
    int r=0;

    vector<long long>cnt(n+1,0);
    int distn=0;
    long long dists=0;


    
    
    for (int l=0;l<n;l++){
        while (r<n&&distn<k){
            cnt[v[r]]++;
            if (cnt[v[r]]==1){
                distn++;
            }
            r++;

        }
        if (distn==k){
            dists+=n-r+1;
        }
        cnt[v[l]]--;
        if (cnt[v[l]]==0){
            distn--;
        }
    }
    cout<<dists<<endl;
}
