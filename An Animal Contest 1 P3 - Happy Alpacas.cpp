#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,x;
    cin>>n>>x;

    if (x==n){
        for (int i=0;i<n;i++){
            cout<<2;
            if (i!=n-1){
                cout<<" ";
            }
        }
        cout<<endl;
        return 0;
    }

    if (x==n-1){
        cout<<-1;
        cout<<endl;
        return 0;
    }

    if ((n-x)%2==1){
        cout<<-1<<endl;
        return 0;
    }
    
    

    int swaps=n-x;

    int cur=1;

    vector<int>v(n);
    for (int i=0;i<n;i++){
        v[i]=cur;

        if (swaps>0){
            cur=3-cur;
            swaps--;
        }
    }

    for (int i=0;i<n;i++){
        cout<<v[i];

        if (i!=n-1){
            cout<<" ";
        }
    }
    cout<<endl;
    
    
    
}
