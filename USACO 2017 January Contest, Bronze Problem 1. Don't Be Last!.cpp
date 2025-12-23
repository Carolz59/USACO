#include <bits/stdc++.h>
using namespace std;

int main(){
    //Bessie, Elsie, Daisy, Gertie, Annabelle, Maggie, and Henrietta
    freopen("notlast.in","r",stdin);
    freopen("notlast.out","w",stdout);
    int n;
    string cow;
    int amount;
    cin>>n;
    map<string,int>log{{"Bessie",0},{"Elsie",0},{"Daisy",0},{"Gertie",0},{"Annabelle",0},{"Maggie",0},{"Henrietta",0}};
    for (int i=0;i<n;i++){
        cin>>cow>>amount;
        log[cow]+=amount;

    }
    set<int>milk;

    for (auto [k,v]:log){
        milk.insert(v);
    }

    if (milk.size()<2){
        cout<<"Tie";
        return 0;
    }

    auto it=milk.begin();
    it++;
    int second=*it;
    vector<string>sec;

    for (auto [k,v]:log){
        if (v==second){
            sec.push_back(k);
        }

        
    }
    if (sec.size()>1){
        cout<<"Tie";
    }else{
        cout<<sec[0];
    }



}
