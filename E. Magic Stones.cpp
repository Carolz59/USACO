//https://codeforces.com/contest/1110/problem/E

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin>>n;

    vector<long long>a(n),b(n);
    for (int i=0;i<n;i++){
        cin>>a[i];

    }
    for (int i=0;i<n;i++){
        cin>>b[i];

    }

    if (a[0]!=b[0]||a[n-1]!=b[n-1]){
        cout<<"NO"<<endl;
        return 0;
    }

    vector<long long>da,db;

    for (int i=1;i<n;i++){
        da.push_back(a[i]-a[i-1]);
        db.push_back(b[i]-b[i-1]);

    }
    sort(da.begin(),da.end());
    sort(db.begin(),db.end());
    if (da==db){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }


}
