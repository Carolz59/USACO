#include<bits/stdc++.h>

using namespace std;

bool amimentallystable=false;

int main(){
    int same,diff,group;
    string p1,p2,p3;
    vector<pair<string,string>>tog;
    vector<pair<string,string>>sep;
    unordered_map<string,int>groups;
    cin>>same;
    for (int i=0;i<same;i++){
        cin>>p1>>p2;
        tog.push_back(make_pair(p1,p2));

    }

    cin>>diff;
    for (int i=0;i<diff;i++){
        cin>>p1>>p2;
        sep.push_back(make_pair(p1,p2));

    }
    cin>>group;
    for (int i=0;i<group;i++){
        cin>>p1>>p2>>p3;
        groups[p1]=i;
        groups[p2]=i;
        groups[p3]=i;

    }

    int count=0;

    for (auto&u:tog){
        if(groups[u.first]!=groups[u.second]){
            count++;
        }
    }

    for (auto&u:sep){
        if(groups[u.first]==groups[u.second]){
            count++;
        }
    }

    cout<<count<<endl;

}
