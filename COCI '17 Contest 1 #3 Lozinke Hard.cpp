#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    map<string,int>m;
    vector<int>res;

    for (int z=0;z<n;z++){
        int t;
        string s;
        cin>>t>>s;
        if (t==1){
            set<string>seen;
            for (int i=0;i<s.size();i++){
                string temp="";
                for (int j=i;j<s.size();j++){
                    temp+=s[j];
                    if (!seen.count(temp)){
                        m[temp]++;
                        seen.insert(temp);
                    }
                    
                    
                }
            }
        }else{
            res.push_back(m[s]);
        }
    }

    for (auto u:res){
        cout<<u<<endl;
    }
    
}
