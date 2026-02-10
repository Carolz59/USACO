#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long l,u;
    cin>>l>>u;

    int cnt=0;

    for (long long i=1; ;i++){
        if (pow(i,6)>u){
            break;
        }
        if (pow(i,6)>=l){
            cnt++;
        }
    }

    cout<<cnt;


}
