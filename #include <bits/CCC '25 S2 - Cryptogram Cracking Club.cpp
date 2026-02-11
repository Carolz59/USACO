#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    long long n;
    cin>>s>>n;
    vector<pair<char,long long>>v;
    long long start=0;
    
    for (int i=0;i<s.size();){
        char c=s[i];
        i++;
        string num="";
        
        while (i<s.size()&&isdigit(s[i])){
            num+=(s[i]);
            i++;
        }
        long long cur=1;
        cur=stoll(num);
        v.push_back({c,cur+start});
        start=cur+start;
        
    }
    long long check=(n+1)%start;
    if (check==0){
        cout<<v.back().first;
        return 0;
    }
    for (auto [ch,en]:v){
        if (en>=check){
            cout<<ch<<endl;
            return 0;
        }
    }

}
