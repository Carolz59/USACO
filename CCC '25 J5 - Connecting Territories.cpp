#include <bits/stdc++.h>
using namespace std;

int r,c,m;

int solve(){
    vector<int>pre(c),cur(c);
    for (int i=0;i<c;i++){
        pre[i]=(i+1)%m;
        if (pre[i]==0){
            pre[i]=m;
        }

    }
    
    for (int i=1;i<r;i++){
        for (int j=0;j<c;j++){
            int val=((i*c)+j+1)%m;
            if (val==0){
            val=m;
        }
            if (j==0){
                int adder=min(pre[j],pre[j+1]);
                cur[j]=val+adder;

            }else if(j==c-1){
                int adder=min(pre[j],pre[j-1]);
                cur[j]=val+adder;

            }else{
                int adder=min(pre[j],min(pre[j-1],pre[j+1]));
                cur[j]=val+adder;
            }

        }
        pre=cur;
        
        

    }
    int smol=INT_MAX;
    for (int i=0;i<c;i++){
        if (smol>pre[i]){
            smol=pre[i];
        }

    }
    return smol;
    


}

int main(){
    cin>>r>>c>>m;

    cout<<solve();




}
