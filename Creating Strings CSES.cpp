#include<bits/stdc++.h>
using namespace std;

string s;
vector<int>f;
vector<string>output;

void perm(string ss){
    if (ss.size()==s.size()){
        output.push_back(ss);
        return;
    }
    for (int i=0;i<26;i++){
        if (f[i]>0){
            f[i]--;
            perm(ss+(char)('a'+i));
            f[i]++;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>s;
    f.resize(26);
    for (int i=0;i<s.size();i++){
        f[s[i]-'a']++;
    }
    perm("");

    cout<<output.size()<<endl;
    for (auto u:output){
        cout<<u<<endl;
    }

    
    
    
}
