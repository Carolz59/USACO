#include <bits/stdc++.h>
using namespace std;


int main(){
    //freopen("sleepy.in","r",stdin);
    //freopen("sleepy.out","w",stdout);
    string a,b,f;

    getline(cin,a);
    getline(cin,b);
    getline(cin,f);

//{encrypt,decrypt}
    map<char,char>key;
    set<char>alpha;
    
    for (char c='A';c<='Z';c++){
        key.insert({c,'.'});
        alpha.insert({c});

    }
    key.insert({' ','.'});
    alpha.insert(' ');

    for (int i=0;i<b.size();i++){
        key[b[i]]=a[i];
        alpha.erase(a[i]);
        
    }
    int cnt=0;
    char unknown;
    for (auto n:key){
        if(n.second=='.'){
            cnt++;
            unknown=n.first;
        }

    }
    if (cnt==1){
        key[unknown]=*alpha.begin();

    }


    for (int i=0;i<f.size();i++){
        if (key.count(f[i])){
            cout<<key[f[i]];
        }else{
            cout<<'.';
        }
        
    }
    cout<<endl;
}

    
