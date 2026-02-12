#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m,n,q;
    cin>>n>>m>>q;

    vector<int>r(n+1,0);
    vector<int>c(m+1,0);
    

    for (int i=0;i<q;i++){
        string t;
        int num;
        cin>>t>>num;

        if (t=="R"){
            r[num]^=1;
            
        }else{
            c[num]^=1;

        }
        

    }
    
    int oddr=0;
    int oddc=0;

    for (int i=1;i<=n;i++){
        if (r[i]==1){
            oddr++;
        }

    }
    for (int i=1;i<=m;i++){
        if (c[i]==1){
            oddc++;
        }
        
    }

    int evenr=n-oddr;
    int evenc=m-oddc;

    int ans=evenr*oddc+evenc*oddr;
    cout<<ans;

    
}
