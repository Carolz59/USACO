#include<bits/stdc++.h>
using namespace std;

int h,j,n;
vector<bool>valid;
vector<int>dist;
set<int>s;

int bfs(){
    queue<int>q;
    q.push(0);
    dist[0]=0;
    s.erase(0);
    int ans=INT_MAX;

    while (!q.empty()){
        int cur=q.front();
        q.pop();
        if (cur>=h){
            ans=min(dist[cur],ans);
            continue;
        }
        int up=cur+j;

        if (up>=h){
            ans=min(dist[cur]+1,ans);
            continue;
        }
        if (s.count(up)&&dist[up]==-1){
            dist[up]=dist[cur]+1;
            q.push(up);
            s.erase(up);
        }

        auto it=s.begin();

        while (it!=s.end()&&*it<cur){
            q.push(*it);
            dist[*it]=dist[cur]+1;
            it=s.erase(it);

        }

        
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>h>>j>>n;

    dist.assign(h+1,-1);
    valid.assign(h+1,true);

    for (int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        for (int z=a;z<=b;z++){
            valid[z]=false;
        }
    }
    for (int i=0;i<=h;i++){
        if (valid[i]){
            s.insert(i);
        }
    }

    int res=bfs();

    if (res==INT_MAX){
        cout<<-1;
    }else{
        cout<<res;
    }


    
}
