#include <bits/stdc++.h>
using namespace std;
 
int main() {
    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);
 
    int n;
    cin>>n;
    vector<pair<int,int>>sf;

    for (int i=0;i<n;i++){
        int s;
        int f;
        cin>>s>>f;
        sf.push_back({s,f});

    }

    sort(sf.begin(),sf.end());

    

    int time=0;

    for (int i=0;i<sf.size();i++){
        if (time<=sf[i].first){
            
            time=sf[i].first+sf[i].second;
            
        }else{
            time+=sf[i].second;
        }
    }
    cout<<time;
 
}
