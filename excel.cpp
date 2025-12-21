#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    long long res=0;
    for(char c:s){
        res = res*26 +(c-'A'+1);
    }
    cout<<res;
}
