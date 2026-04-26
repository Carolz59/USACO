#include<bits/stdc++.h>
using namespace std;
vector<long long>v;
int n;
bool alt(int x){
    if (x==0&&v[x]!=v[x+1]){
        return true;
    }
    if (x==n-1&&v[x]!=v[x-1]){
        return true;
    }

    if (v[x-1]>v[x]&&v[x+1]>v[x]){
        return true;
    }
    if (v[x-1]<v[x]&&v[x+1]<v[x]){
        return true;
    }
    return false;
}

bool good(){
    for (int i=0;i<n;i++){
        if (!alt(i)){
            return false;
        }
    }
    return true;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    cin>>n;
    v.resize(n);
    for (int i=0;i<n;i++){
        cin>>v[i];
    }
    if (good()){
        cout<<0<<endl;
        return 0;
    }

    for (int i=0;i<n-1;i++){

        if (v[i]==v[i+1]){
            for (auto u:{-1,1}){
                v[i]+=u;
                if (good()){
                    cout<<1;
                    return 0;
                }else{
                    v[i]-=u;
                }
            }
            for (auto u:{-1,1}){
                v[i+1]+=u;
                if (good()){
                    cout<<1;
                    return 0;
                }else{
                    v[i+1]-=u;
                }
            }
        }


    }
    cout<<-1<<endl;



}
