#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin>>k;

    vector<int>comps;
    int used=0;
    while (k!=0){
        int v=1;

        while(((v+1)*(v))/2<=k){
            v++;

        }
        while (used+v>5000){
            v--;
        }

        comps.push_back(v);
        used+=v;
        k-=(v*(v-1))/2;
    }

    cout<<used<<" "<<comps.size()-1+used<<endl;

    int cur=1;
    for (int u=0;u<comps.size();u++){
        vector<int>nodes;
        for (int i=0;i<comps[u];i++){
            nodes.push_back(cur);
            cur++;

        }

        for (int i=0;i<nodes.size();i++){
            cout<<nodes[i]<<" "<<nodes[(i+1)%comps[u]]<<endl;
        }

        if (u!=comps.size()-1){
            cout<<cur<<" "<<cur-1<<endl;
        }
    }


}
