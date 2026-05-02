#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,d,w;
    cin>>n>>d>>w;

    vector<int>v(n);

    for (int i=0;i<n;i++){
        cin>>v[i];
    }

    sort(v.begin(),v.end());

    int i=0;
    int ans=0;
    while (i<n){
        int counter=1;
        int temp=v[i];
        while (counter<d&&i+counter<n){
            if(v[i+counter]-temp<=w){
                counter++;
            }else{
                break;
            }
            
            
        }
        i+=counter;
        ans++;

    }

    cout<<ans;


}
