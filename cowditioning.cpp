#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>>cows,acs;
vector<int>need,pwr,prc;
int best=1e9;

int chk(string s){
    vector<int>v(101);
    for(int i=1;i<=100;i++){
        for(int j=0;j<acs.size();j++){
            if(s[j]=='1'&&acs[j].first<=i&&acs[j].second>=i){
                v[i]+=pwr[j];
            }
        }
    }
    for(int i=0;i<cows.size();i++){
        for(int j=cows[i].first;j<=cows[i].second;j++){
            if(v[j]<need[i]) return 1e9;
        }
    }
    int sum=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='1') sum+=prc[i];
    }
    return sum;
}

void gen(string s,int m){
    if(s.size()==m){
        best=min(best,chk(s));
        return;
    }
    gen(s+"1",m);
    gen(s+"0",m);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        int l,r,x;
        cin>>l>>r>>x;
        cows.push_back({l,r});
        need.push_back(x);
    }
    for(int i=0;i<m;i++){
        int l,r,p,c;
        cin>>l>>r>>p>>c;
        acs.push_back({l,r});
        pwr.push_back(p);
        prc.push_back(c);
    }

    gen("",m);
    cout<<best<<"\n";
}
