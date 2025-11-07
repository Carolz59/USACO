#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector<int>boi;
    boi.push_back(0);
    int tot=0;
    for (int i=0;i<4;i++){
        cin>>n;
        tot+=n;
        boi.push_back(tot);

    }
    
for (int i=0;i<5;i++){//i as 0
    for (int j=0;j<5;j++){
        cout<<abs(boi[i]-boi[j])<<" ";
    }
    cout<<endl;
   }


}
