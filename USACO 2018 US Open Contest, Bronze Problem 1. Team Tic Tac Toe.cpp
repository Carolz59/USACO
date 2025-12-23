#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("tttt.in","r",stdin);
    freopen("tttt.out","w",stdout);
    string a;
    vector<string>grid;
    for (int i=0;i<3;i++){
        cin>>a;
        grid.push_back(a);
    }

    set<char>ind;
    set<pair<char,char>>team;

    vector<vector<char>>lines;

    for (int i=0;i<3;i++){
        lines.push_back({grid[i][0],grid[i][1],grid[i][2]});
    }
    for (int i=0;i<3;i++){
        lines.push_back({grid[0][i],grid[1][i],grid[2][i]});
    }
    lines.push_back({grid[0][0],grid[1][1],grid[2][2]});
    lines.push_back({grid[0][2],grid[1][1],grid[2][0]});

    for (auto l:lines){
        set<char>s(l.begin(),l.end());

        if (s.size()==1){
            ind.insert(*s.begin());
        }else if(s.size()==2){
            auto it=s.begin();
            char a=*it;
            ++it;
            char b=*it;
            team.insert({min(a,b),max(a,b)});


        }

    }
    cout<<ind.size()<<endl;
    cout<<team.size()<<endl;
}
