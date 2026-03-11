#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q;
    cin>>n>>q;
    vector<vector<int>>pos(1000001);
    for (int i=1;i<=n;i++){
        int p;
        cin>>p;
        pos[p].push_back(i);

    }

    while (q--){
        int l,r,p;
        cin>>l>>r>>p;
        bool found=false;

        for (int i=1;i*i<=p;i++){
            if (p%i!=0){
                continue;
            }
            int a=i;
            int b=p/i;
            if (a==b){
                continue;
            }
            if (!pos[a].empty()&&!pos[b].empty()){
                auto it1=lower_bound(pos[a].begin(),pos[a].end(),l);
                auto it2=lower_bound(pos[b].begin(),pos[b].end(),l);
                if ((it1!=pos[a].end()&&*it2<=r&&it2!=pos[b].end()&&*it1<=r)){
                    cout<<"YES"<<endl;
                    found=true;
                    break;
                }
                
            }
        }
        if (!found){
            cout<<"NO"<<endl;
        }
    }
    
    

}
