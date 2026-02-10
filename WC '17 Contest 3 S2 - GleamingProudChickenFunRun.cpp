#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<pair<int,int>>ev;

    for (int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        ev.push_back({a,b});
        ev.push_back({b,-a});
        
    }

    int cnt=0;
    int covmax=-1;
    int cov=-1;
    

    sort(ev.begin(),ev.end());

    for (int i=0;i<2*n;i++){
        auto [s,f]=ev[i];
        if (f>0){
            covmax=max(covmax,f);
        }else{
            if (cov<=-f){
                cnt++;
                cov=covmax;
            }
            
        }
    }

    cout<<cnt;
    
}
