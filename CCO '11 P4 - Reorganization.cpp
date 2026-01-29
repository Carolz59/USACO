#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    vector<int> rank(n+1);
    set<pair<int,int>>ava;
    vector<int>child(n+1,0);
    ava.insert({1,1});
    for (int i=1;i<=n;i++) {
        cin>>rank[i];
    }


    if (rank[1]!=1&&rank[1]==6){
        cout<<"NO";
        return 0;
    }

    for (int i=2;i<=n;i++){
        auto it=ava.lower_bound({rank[i],12414});
        if (it==ava.begin()){
            cout<<"NO";
            return 0;

        }
        it--;

        int sup=it->second;
        child[sup]++;
        if (child[sup]==2){
            ava.erase(it);
        }

        ava.insert({rank[i],i});

    }
    cout<<"YES";


    
}
