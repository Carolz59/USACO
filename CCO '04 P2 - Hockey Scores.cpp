#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>>v,last;

        while (n--){
            int x,y;
            char c;
            cin>>x>>c>>y;

            if (x>y){
                swap(x,y);
            }
            v.push_back({x,y});

        }

        sort(v.begin(),v.end());
        vector<vector<pair<int,int>>>lol;
        last.push_back({v[0].first,v[0].second});
        lol.push_back({{v[0].first,v[0].second}});
        for (int i=1;i<v.size();i++){
            auto [a,b]=v[i];

            bool fit=false;
            for (int j=0;j<last.size();j++){
                auto [c,d]=last[j];
                if (a>=c&&b>=d){
                    last[j]={a,b};
                    lol[j].push_back({a,b});
                    fit=true;
                    break;
                }
            }
            if (!fit){
                last.push_back({a,b});
                lol.push_back({{a,b}});

            }

        }
        cout<<lol.size()<<endl;
        for (auto u:lol){
            for (auto [a,b]:u){
                cout<<a<<"-"<<b<<" ";
            }
            cout<<endl;
        }
        
            
    }
        
}

