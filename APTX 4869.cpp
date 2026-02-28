#include<bits/stdc++.h>
using namespace std;

int i=0;
string s;

map<string,int>rec(){
    map<string,int>m;
    
    while (s[i]!=')'&&i<s.size()){
        if (s[i]=='('){
            i++;
            auto ins=rec();
            i++;

            int num=0;

            while (i<s.size()&&isdigit(s[i])){
                num=num*10+s[i]-'0';
                i++;
            }
            if (num==0){
                num=1;
            }

            for (auto [str,cnt]:ins){
                m[str]+=num*cnt;
            }

        }else{
            string cur="";
            cur+=s[i];
            i++;
            while (i<s.size()&&islower(s[i])){
                cur+=s[i];
                i++;

            }
            int num=0;
            while (i<s.size()&&isdigit(s[i])){
                num=num*10+s[i]-'0';
                i++;
            }
            if (num==0){
                num=1;
            }
            m[cur]+=num;

        }
    }
    return m;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>s;

    auto ans=rec();
    

    for (auto [str,num]:ans){
        if (num==1){
            cout<<str;
            continue;
        }
        cout<<str<<num;
    }
}
