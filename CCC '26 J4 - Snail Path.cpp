#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    set<pair<int,int>>s;
    int curx=0;
    int cury=0;
    int ans=0;
    s.insert({0,0});
    for (int i=0;i<n;i++){
        string c;
        cin>>c;
        int d;
        if (c.size()==2){
            d=c[1]-'0';

        }else{
            string temp="";
            temp+=c[1];
            temp+=c[2];
            d=stoi(temp);
        }
        if (c[0]=='N'){
            for (int j=0;j<d;j++){
                cury++;
                if (s.count({curx,cury})){
                    ans++;
                }else{
                    s.insert({curx,cury});
                }
            }
        }else if (c[0]=='S'){
            for (int j=0;j<d;j++){
                cury--;
                if (s.count({curx,cury})){
                    ans++;
                }else{
                    s.insert({curx,cury});
                }
            }

        }else if (c[0]=='W'){
            for (int j=0;j<d;j++){
                curx--;
                if (s.count({curx,cury})){
                    ans++;
                }else{
                    s.insert({curx,cury});
                }
            }

        }else{
            for (int j=0;j<d;j++){
                curx++;
                if (s.count({curx,cury})){
                    ans++;
                }else{
                    s.insert({curx,cury});
                }
            }

        }
        

    }
    cout<<ans;


    
}
