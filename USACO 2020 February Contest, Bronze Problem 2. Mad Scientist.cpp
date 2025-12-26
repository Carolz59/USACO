#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("notlast.in","r",stdin);
    //freopen("notlast.out","w",stdout);

    int n;
    string a,b;
    cin>>n>>a>>b;

    bool nah=false;
    int cnt=0;
    for (int i=0;i<n;i++){
        if (a[i]!=b[i]){
            if (nah==false){
                cnt++;
                nah=true;
            }
        }else{
            nah=false;
        }
    }
    cout<<cnt;

}
