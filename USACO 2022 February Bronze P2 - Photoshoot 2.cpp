#include <bits/stdc++.h>
using namespace std;


int main(){
    //freopen("paint.in","r",stdin);
    //freopen("paint.out","w",stdout);
    int n;
    cin>>n;
    vector<int>a(n),b(n),pos(n);
    for (int i=0;i<n;i++){
        cin>>a[i];

    }
    for (int i=0;i<n;i++){
        cin>>b[i];
        pos[b[i]]=i;

    }

    int m=-1;
    int cnt=0;
    for(auto i:a){
        if (pos[i]>m){
            m=pos[i];
        }else{
            cnt++;
        }
    }
    cout<<cnt;

    
    
    
}
