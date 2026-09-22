#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,b,t;
    cin>>n>>b>>t;
    long long ansb=0,anst=0;

    vector<long long>v(n);
    for (int i=0;i<n;i++){
        cin>>v[i];
    }

    long long l=0;
    deque<pair<long long,long long>>hi,lo;
    for (int r=0;r<n;r++){
        while(!hi.empty()&&hi.back().second<=v[r]){
            hi.pop_back();
        }
        hi.push_back({r,v[r]});
    
        while(!lo.empty()&&lo.back().second>=v[r]){
            lo.pop_back();
        }
        lo.push_back({r,v[r]});

        while (!hi.empty()&&!lo.empty()&&hi.front().second-lo.front().second>t){
            l++;
            while (!hi.empty()&&hi.front().first<l){
                hi.pop_front();
            }
            while (!lo.empty()&&lo.front().first<l){
                lo.pop_front();
            }
        }
        anst+=r-l+1;


    }

    hi.clear();
    lo.clear();
    l=0;
    for (int r=0;r<n;r++){
        while(!hi.empty()&&hi.back().second<=v[r]){
            hi.pop_back();
        }
        hi.push_back({r,v[r]});
    
        while(!lo.empty()&&lo.back().second>=v[r]){
            lo.pop_back();
        }
        lo.push_back({r,v[r]});

        while (!hi.empty()&&!lo.empty()&&hi.front().second-lo.front().second>=b){
            l++;
            while (!hi.empty()&&hi.front().first<l){
                hi.pop_front();
            }
            while (!lo.empty()&&lo.front().first<l){
                lo.pop_front();
            }
        }
        ansb+=r-l+1;


    }
    cout<<anst-ansb;

    
}
