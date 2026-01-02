#include <bits/stdc++.h>
using namespace std;


int main(){
    freopen("factory.in","r",stdin);
    freopen("factory.out","w",stdout);
    int n;
    cin>>n;
    vector<int>in(n+1),out(n+1);

    for (int i=1;i<n;i++){
        
        int a,b;
        cin>>a>>b;
        out[a]++;
        in[b]++;

    }
    

    int ans=-1;
    for (int i=1;i<n+1;i++){
        if (out[i]==0&&ans==-1){
            ans=i;

        }else if (out[i]==0&&ans!=-1){
            ans=-1;
            break;

        }

    }
    cout<<ans<<endl;
    
}
