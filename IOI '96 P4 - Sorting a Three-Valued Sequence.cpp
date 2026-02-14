#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int>v(n+1);
    map<int,int>cnt;
    vector<queue<int>>pos(7,queue<int>());

    
    //1 for 2 in 1
    //2 for 3 in 1
    //3 for 1 in 2
    //4 for 3 in 2
    //5 for 1 in 3
    //6 for 2 in 3

    for (int i=1;i<=n;i++){
        cin>>v[i];
        cnt[v[i]]++;

    }

    for (int i=1;i<=cnt[1];i++){
        if (v[i]==2){
            pos[1].push(i);
        }else if (v[i]==3){
            pos[2].push(i);
        }
    }

    for (int i=cnt[1]+1;i<=cnt[2]+cnt[1];i++){
        if (v[i]==1){
            pos[3].push(i);
        }else if (v[i]==3){
            pos[4].push(i);
        }
    }

    for (int i=cnt[1]+cnt[2]+1;i<=cnt[3]+cnt[2]+cnt[1];i++){
        if (v[i]==1){
            pos[5].push(i);
        }else if (v[i]==2){
            pos[6].push(i);
        }
    }

    vector<pair<int,int>>swaps;

    //2 in 1, 1 in 2(1,3)
    int num=min(pos[1].size(),pos[3].size());

    while (num--){
        int p1=pos[1].front();
        int p2=pos[3].front();
        pos[1].pop();
        pos[3].pop();
        swaps.push_back({p1,p2});


    }

    //3 in 1, 1 in 3(2,5)
    num=min(pos[2].size(),pos[5].size());

    while (num--){
        int p1=pos[2].front();
        int p2=pos[5].front();
        pos[2].pop();
        pos[5].pop();
        swaps.push_back({p1,p2});


    }


    //3 in 2, 2 in 3(4,6)
    num=min(pos[4].size(),pos[6].size());

    while (num--){
        int p1=pos[4].front();
        int p2=pos[6].front();
        pos[4].pop();
        pos[6].pop();
        swaps.push_back({p1,p2});

    }

    //2 in 1(1)
    //3 in 2(4)
    //1 in 3(5)

    int s=pos[1].size();
    while (s--){
        auto p1=pos[1].front();
        auto p2=pos[4].front();
        auto p3=pos[5].front();
        pos[1].pop();
        pos[4].pop();
        pos[5].pop();
        swaps.push_back({p1,p2});
        swaps.push_back({p2,p3});
    }

    //1 in 2(2)
    //3 in 1(3)
    //2 in 3(6)

    s=pos[2].size();
    while (s--){
        auto p1=pos[2].front();
        auto p2=pos[3].front();
        auto p3=pos[6].front();
        pos[2].pop();
        pos[3].pop();
        pos[6].pop();
        swaps.push_back({p1,p2});
        swaps.push_back({p2,p3});
    }

    cout<<swaps.size()<<endl;
    for (auto [a,b]:swaps){
        cout<<a<<" "<<b<<endl;
    }


    }

