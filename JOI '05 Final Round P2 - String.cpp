#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    cin>>n>>s;


    for (int i=0;i<n;i++){
        int cnt=1;
        string ne="";
        char cur=s[0];
        for (int j=0;j<s.size()-1;j++){
            if (s[j]==s[j+1]){
                cnt++;
            }else{
                ne+=to_string(cnt)+cur;
                cur=s[j+1];
                cnt=1;
            }
            
        }
        ne+=to_string(cnt)+cur;
        s=ne;
    }
    cout<<s<<endl;
}
