#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    vector<long double>h,b;

    for (int i=0;i<n+1;i++){
        long double hei;
        cin>>hei;
        h.push_back(hei);

    }

    for (int i=0;i<n;i++){
        long double bas;
        cin>>bas;
        b.push_back(bas);

    }

    int l=0;int r=1;

    long double area=0;
    while (r<=n){
        area+=((h[l]+h[r])*b[l])/2.0;
        l++;
        r++;
    }

    cout<<fixed<<area;


    
}
