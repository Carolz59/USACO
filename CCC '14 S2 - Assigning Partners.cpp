#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<string>v1,v2;
    for (int i=0;i<n;i++){
        string s;
        cin>>s;
        v1.push_back(s);
    }
    for (int i=0;i<n;i++){
        string s;
        cin>>s;
        v2.push_back(s);
    }

    map<string,set<string>>cnt;
    for (int i=0;i<n;i++){

        if (v1[i]==v2[i]){
            cout<<"bad"<<endl;
            return 0;
        }
        cnt[v1[i]].insert(v2[i]);
        cnt[v2[i]].insert(v1[i]);
        if (cnt[v1[i]].size()>1||cnt[v2[i]].size()>1){
            cout<<"bad"<<endl;
            return 0;
        }
        
    }
    cout<<"good"<<endl;
    return 0;

    
    
    
}
