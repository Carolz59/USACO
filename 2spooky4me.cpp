#include<bits/stdc++.h>
using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long d,n,s;
    cin>>d>>n>>s;

    vector<pair<long long,long long>>house;
    for (int i=0;i<d;i++){
        long long start,end,val;
        cin>>start>>end>>val;
        house.push_back({start,val});
        house.push_back({end+1,-val});
    }
    
    house.push_back({n+1,0});
    sort(house.begin(),house.end());

    long long scare=0;

    for (int i=0;i+1<house.size();i++){
        scare+=house[i].second;

        if (scare>=s){
            n-=house[i+1].first-house[i].first;
        }

    }
    cout<<n<<endl;
}
