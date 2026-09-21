#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for (int i=0;i<n;i++){
        cin>>v[i];
    }
    deque<pair<int,int>>lo,hi;
    int l=0;
    long long cnt=0;
    
    for (int r=0;r<n;r++){
        while (!lo.empty()&&lo.back().second>=v[r]){
            lo.pop_back();
        }
        lo.push_back({r,v[r]});

        while (!hi.empty()&&hi.back().second<=v[r]){
            hi.pop_back();
        }
        hi.push_back({r,v[r]});

        while (!hi.empty()&&!lo.empty()&&hi.front().second-lo.front().second>k){
            l++;
            while(!hi.empty()&&hi.front().first<l){
                hi.pop_front();
            }
            while(!lo.empty()&&lo.front().first<l){
                lo.pop_front();
            }

        }
        cnt+=1LL*(r-l+1);

    }
    cout<<cnt;



    
}
