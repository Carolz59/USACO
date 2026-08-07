#include<bits/stdc++.h>
using namespace std;

int main(){
    //pref[i]+(j-i)-(pref[j]-pref[i])+(pref[n]-pref[j])=2*pref[i]-i-2*pref[j]+j+pref[n]
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin>>q;
    while (q--){
        int n;
        cin>>n;
        vector<int>pref(n+1);
        for (int i=1;i<=n;i++){
            char a;
            cin>>a;
            pref[i]=pref[i-1]+(a=='W'); 
        }
        int besti=2*pref[1]-1;
        int besttot=n;
        for (int j=2;j<n;j++){
            besttot=min(besttot,besti-2*pref[j]+j+pref[n]);
            besti=min(besti,2*pref[j]-j);

        }
        cout<<besttot<<endl;

    }

}
