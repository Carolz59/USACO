#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>w(2002,0),b(4004,0);
    for (int i=0;i<n;i++){
        int x;
        cin>>x;
        w[x]++;

    }

    for (int i=1;i<w.size();i++){
        if (w[i]>=1){
            if (w[i]>1){
                b[i*2]+=w[i]/2;
            }
            for (int j=i+1;j<w.size();j++){
                if (w[j]>=1){
                    b[i+j]+=min(w[i],w[j]);
                }
        }

        
        }

    }

    int ans=0;
    int uni=0;
    for (int i=1;i<=b.size();i++){
        if (ans<b[i]){
            ans=b[i];
            
        }
        
    }

    for (int i=1;i<=b.size();i++){
        if (b[i]==ans){
            uni++;
        }
        
    }

    cout<<ans<<" "<<uni;


}
