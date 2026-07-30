#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    vector<int>psa(n+1);
    vector<int>first(k,-1);
    for (int i=1;i<=n;i++){
        int p;
        cin>>p;
        psa[i]=psa[i-1]+p;
        psa[i]%=k;
        
    }
    int best=-1;

    first[0]=0;
    for (int i=1;i<=n;i++){
        if (first[psa[i]]==-1){
            first[psa[i]]=i;
        }else{
            best=max(best,i-first[psa[i]]);
        }
    }
    cout<<best;


}
