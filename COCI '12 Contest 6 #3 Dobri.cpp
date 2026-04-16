#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    vector<int>v(n);

    for (int i=0;i<n;i++){
        cin>>v[i];
    }

    unordered_set<int>sum;
    int tot=0;

    for (int i=0;i<n;i++){
        for (int j=i-1;j>=0;j--){
            if (sum.count(v[i]-v[j])){
                tot++;
                break;
            }
        }

        for (int z=0;z<=i;z++){
            sum.insert(v[i]+v[z]);
        }
    }

    cout<<tot;
}
