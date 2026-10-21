#include<bits/stdc++.h>
using namespace std;

long long sum(string n){
    long long s=0;
    for (int i=0;i<(long long)n.size();i++){
        s+=n[i]-'0';
    }
    return s;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long q;
    cin>>q;

    while (q--){
        string s,f;
        cin>>s>>f;
        
        long long best=sum(f);

        for (int i=0;i<(long long)f.size();i++){
            string cur=f;
            if (f[i]=='0'){
                continue;
            }
            cur[i]--;
            for (int j=i+1;j<(long long)f.size();j++){
                cur[j]='9';
            }
            if (stoll(cur)>=stoll(s)&&stoll(cur)<=stoll(f)){
                best=max(best,sum(cur));
            }
        }
        cout<<best<<endl;


    }
    

    

    
    
}
