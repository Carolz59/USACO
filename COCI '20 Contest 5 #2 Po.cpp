#include<bits/stdc++.h>
using namespace std;
//1 2 3 2 1 3
//1 1 1 1 1 1
//1 2 2 2 1 1
//1 2 3 3 1 1
//1 2 3 3 1 3
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cin>>n;
    stack<int>s;
    long long ans=0;
    for (int i=0;i<n;i++){
        long long a;
        cin>>a;
        while (!s.empty()&&s.top()>a){
            s.pop();
        }
        if (a==0){
            continue;
        }
        if (s.empty()||s.top()<a){
            s.push(a);
            ans++;
        }
    }
    cout<<ans;

    
}
