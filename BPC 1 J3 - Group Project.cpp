#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    vector<long long>v(2*n);

    for (int i=0;i<n*2;i++){
        cin>>v[i];

    }

    sort(v.begin(),v.end());

    int cnt=0;

    for (int i=0;i+1<v.size();i+=2){
        cnt+=v[i+1]-v[i];
    }
    cout<<cnt<<endl;

    
}
