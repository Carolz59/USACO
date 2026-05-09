#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<int>v(n);

    for (int i=0;i<n;i++){
        cin>>v[i];
    }

    for (int i=0;i<n;i++){
        int x;
        cin>>x;
        v[i]=x-v[i];
    }

    int l=0;
    int r=0;
    int moves=0;
    while (l<=n-1){
        if (v[l]==0&&l<n){
            l++;
            continue;
        }
        r=l;
        int mark=abs(v[l]);
        while (r<n&&((v[r]^v[l])>=0&&v[r]!=0)){
            mark=min(mark,abs(v[r]));
            r++;

        }
        for (int i=l;i<r;i++){
            if (v[i]>0){
                v[i]-=mark;
            }else{
                v[i]+=mark;
            }
        }
        moves+=mark;

    }
    cout<<moves;


    
}
