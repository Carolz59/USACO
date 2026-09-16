#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cin>>n;
    stack<pair<int,long long>>s;
    for (int i=0;i<n;i++){
        long long x;
        cin>>x;

        while(!s.empty()&&s.top().second>=x){
            s.pop();

        }
        if (s.empty()){
            cout<<0;
        }else{
            cout<<s.top().first+1;
        }
        cout<<" ";
        s.push({i,x});
    }
    
}
