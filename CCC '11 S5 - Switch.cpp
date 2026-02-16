#include <bits/stdc++.h>
using namespace std;

int n;

string turnlight(string s){
    int i=0;
    while (i<n){
        if (s[i]=='0'){
            i++;
            continue;
            
        }else{
            int cnt=0;
            while (i<n&&s[i]=='1'){
                cnt++;
                i++;
            }

            if (cnt>=4){
                for (int j=i-cnt;j<i;j++){
                    s[j]='0';
                }
            }
            
        }
    }
    return s;
}

int hashhhh(string s){
    int base=0;
    for (int i=0;i<n;i++){
        base+=base*2+(s[i]-'0');
    }
    return base;
}

int bfs(string s){
    set<int>visited;
    queue<pair<string,int>>q;
    visited.insert(hashhhh(s));
    q.push({s,0});
    string targ="";
    for (int i=0;i<n;i++){
        targ+='0';
    }

    while (!q.empty()){
        auto [state,num]=q.front();
        q.pop();

        if (state==targ){
            return num;
        }

        for (int i=0;i<n;i++){
            if (state[i]=='0'){
                string next=state;
                next[i]='1';
                if (!visited.count(hashhhh(next))){
                    next=turnlight(next);
                    q.push({next,num+1});
                }
            }
        }
    }
    return -1;

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    string start="";
    for (int i=0;i<n;i++){
        int l;
        cin>>l;
        start+=to_string(l);

    }

    cout<<bfs(start);

    

}
