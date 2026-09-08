#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    long long s;
    cin>>n>>s;
    vector<pair<long long,long long>>v(n);
    for (int i=0;i<n;i++){
        long long val;
        cin>>val;
        v[i]={val,i+1};
    }


    sort(v.begin(),v.end());

    long long l=0,r=n-1;
    while (l<r){
        long long sum=v[l].first+v[r].first;
        if (sum<s){
            l++;
        }else if (sum>s){
            r--;
        }else{
            cout<<v[l].second<<" "<<v[r].second;
            return 0;
        }

    }
    cout<<"IMPOSSIBLE";
    
    
    
}
