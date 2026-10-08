#include<bits/stdc++.h>
using namespace std;

int n;
vector<int>apple;
vector<int>output;
long long lol=0;
long long ans=LLONG_MAX;

void subs(int i, long long tot){
    if (i==n){
        ans=min(ans,abs(lol-tot-tot));
        return;
    }

    subs(i+1,tot);
    subs(i+1,tot+apple[i]);

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    
    for (int i=0;i<n;i++){
        long long x;
        cin>>x;
        lol+=x;
        apple.push_back(x);
    }

    subs(0,0);
    cout<<ans;


    
    
    
}
