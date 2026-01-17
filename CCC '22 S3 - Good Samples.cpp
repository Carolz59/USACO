#include <bits/stdc++.h>
using namespace std;

// 1 2 3 1

int main(){
    long long n,m,k;
    cin>>n>>m>>k;

    vector<long long>seq(n,0);
    
    k-=n;
    seq[0]=1;

    for (int i=1;i<m;i++){
        if (k-i>=0&&i<n){
            seq[i]=i+1;
            k-=i;

        }else{
            break;
        }


    }
    auto it=find(seq.begin(),seq.end(),0);

    int cur;

    if (it==seq.end()){
        cur=n;
    }else{
        cur=it-seq.begin();
    }
    //atp weve pushed all possible unique ones


    for (int i=cur;i<n;i++){
        //from rn on to n, add num to create max possible subarries
        if (k>0){
            for (int j=m;j>0;j--){
                if (k-j+1>=0){
                    k-=(j-1);
                    seq[i]=seq[i-j];
                    break;
            }}

        }else{
            seq[i]=seq[i-1];
        }
    
        
    }

    if (k==0){
        for (int i=0;i<seq.size();i++){
        cout<<seq[i];
        if (i!=n-1){
            cout<<" ";
        }
    }
    }else{
        cout<<-1;
    }
    



}
