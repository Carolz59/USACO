#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int r,n;
    cin>>r;
    vector<char>cur(r);
    for (int i=0;i<r;i++){
        cin>>cur[i];

    }
    cin>>n;
    long long maxans=0;
    long long act=0;
    vector<vector<char>>v(n,vector<char>(r));
    for (int i=0;i<n;i++){
        for (int j=0;j<r;j++){
            cin>>v[i][j];
        }
    }

    for (int i=0;i<r;i++){
        int ro=0,p=0,s=0;
        for (int j=0;j<n;j++){
            if (v[j][i]=='R'){
                ro++;
            }else if(v[j][i]=='S'){
                s++;
            }else{
                p++;
            }
            
        }
        maxans+=max({ro*2+p,p*2+s,s*2+ro});
        if (cur[i]=='S'){
            act+=p*2+s;
        }else if(cur[i]=='R'){
            act+=s*2+ro;
        }else{
            act+=ro*2+p;
        }
    }
    cout<<act<<endl<<maxans;







}
