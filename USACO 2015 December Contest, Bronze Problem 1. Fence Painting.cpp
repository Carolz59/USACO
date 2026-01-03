#include <bits/stdc++.h>
using namespace std;


int main(){
    //freopen("paint.in","r",stdin);
    //freopen("paint.out","w",stdout);

    

    int a,b,c,d;
    cin>>a>>b>>c>>d;

    if (b<c||a>d){
        cout<<b-a+(d-c)<<endl;
        return 0;
    }

    cout<<max(b,d)-min(a,c);
    
}
