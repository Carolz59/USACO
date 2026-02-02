#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,p;
    cin>>n>>p;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;

    int cells;

    for (int i=1;i<n+1;i++){
        int a,b;
        cin>>a>>b;
        if (p==i){
            cells=a;
        }else if(b>a){
            continue;
            
        }else{
            q.push({b,a});
        }
        
        
    }

    int cnt=1;
    while (!q.empty()){
        auto [cost,gain]=q.top();
        q.pop();

        if (cells>=cost){
            cnt++;
            cells+=gain-cost;
        }

    }
    cout<<cells<<endl<<cnt;
}
