#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string n;
    cin>>n;
    string s=n;
    long long sz=s.size();
    for (int i=0;i<sz/2;i++){
        s[sz-i-1]=s[i];

    }
    if (s>n){
        cout<<s;
        return 0;
    }
    long long mid=(sz-1)/2;

    while (mid>=0&&s[mid]=='9'){
        s[mid]='0';
        s[sz-mid-1]='0';
        mid--;
    }
    if (mid<0){
        cout<<"1"<<string(sz-1,'0')<<"1";
        return 0;
    }
    s[mid]++;
    s[sz-mid-1]=s[mid];
    cout<<s;
    return 0;
    

    
    
}
