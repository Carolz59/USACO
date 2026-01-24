#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int cnt=0;

    int fiv=n/5;

    for (int i=0;i<=fiv;i++){
        int tot5=i*5;
        int tot4=n-tot5;
        int div=tot4%4;

        if (div==0&&(tot5+tot4)==n){
            cnt++;
        }
    }
    cout<<cnt;
}
