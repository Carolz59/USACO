#include <bits/stdc++.h>
using namespace std;

bool prime(int x){
    if (x==2){
        return true;

    }else if(x<2){
        return false;
    }

    for (int i=2;i*i<=x;i++){
        if (x%i==0){
            return false;
        }
    }
    return true;


}
int main(){
    int t;
    cin>>t;
    vector<pair<int,int>>ans;

    for (int i=0;i<t;i++){
        int n;
        cin>>n;

        int tot=n*2;

        for (int i=2;i<=tot;i++){
            if (prime(i)&&prime(tot-i)){
                ans.push_back({i,tot-i});
                break;
                
            }

        }
    }
    for (auto [a,b]:ans){
        cout<<a<<" "<<b<<endl;
    }
    

}
