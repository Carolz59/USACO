#include <bits/stdc++.h>
using namespace std;

//Beatrice Belinda Bella Bessie Betsy Blue Buttercup Sue 
vector<string>cows={"Beatrice", "Belinda","Bella","Bessie","Betsy","Blue","Buttercup","Sue"};
map<string,vector<string>>adj;
set<string>visited;
vector<string>seq;

bool bt(){
    if (seq.size()==8){
        for (auto c:seq){
            cout<<c<<endl;
        }
        return true;
    }

    for (auto cow:cows){
        if (visited.count(cow)){
            continue;
        }
        bool ok=true;

        for (auto nei:adj[cow]){
            if(visited.count(nei)){
                if (seq.back()!=nei){
                    ok=false;
                }
            }
        }
        if (!ok){
            continue;
        }
        seq.push_back(cow);
        visited.insert(cow);

        if (bt()){
            return true;
        }
        seq.pop_back();
        visited.erase(cow);

    }
    return false;

}


int main(){
    //freopen("outofplace.in","r",stdin);
    //freopen("outofplace.out","w",stdout);
    int n;
    cin>>n;
    string a,x,b;

    for (int i=0;i<n;i++){
        cin>>a>>x>>x>>x>>x>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);

    }
    bt();
    

}
