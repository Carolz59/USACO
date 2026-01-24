#include <bits/stdc++.h>
using namespace std;

int main(){
    int tog,sep,num;
    cin>>tog;
    vector<pair<string,string>>map1;
    map<string,int>group;
    int cnt=0;

    for (int i=0;i<tog;i++){
        string x,y;
        cin>>x>>y;
        map1.push_back({x,y});
    }

    cin>>sep;
    vector<pair<string,string>>map2;

    for (int i=0;i<sep;i++){
        string x,y;
        cin>>x>>y;
        map2.push_back({x,y});
    }

    cin>>num;

    for (int i=0;i<num;i++){
        string x,y,z;
        cin>>x>>y>>z;
        group[x]=i;
        group[y]=i;
        group[z]=i;
        
    }
    string name1,name2;
    for (int i=0;i<tog;i++){
        name1=map1[i].first;
        name2=map1[i].second;

        if (group[name1]!=group[name2]){
            cnt++;
        }
    }

    for (int i=0;i<sep;i++){
        name1=map2[i].first;
        name2=map2[i].second;

        if (group[name1]==group[name2]){
            cnt++;
        }
    }
    cout<<cnt;
    


}
