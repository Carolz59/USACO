#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<long long>v(n);

    for (int i=0;i<n;i++){
        cin>>v[i];
    }

        if (n<14){
        long double num=-10000;
        int l=0;
        int r=0;

        for (int i=0;i<n;i++){
            long double p=1.0;
            for (int j=i;j<n;j++){
                p*=v[j];
                long double numcur=p/(j-i+1);
                if (numcur>num){
                    num=numcur;
                    l=i;
                    r=j;
                }
            }
        }
        cout<<l+1<<" "<<r+1;
        return 0;
    }

    if (v[0]==1){
        cout<<2<<" "<<n;

    }else if (v[n-1]==1){
        cout<<1<<" "<<n-1;
    }else{
        cout<<1<<" "<<n;
    }

}
