#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    vector<vector<int>>prereq(8);
    vector<int>degree(8,0);
    prereq[1].push_back(7);
    degree[7]++;
    prereq[1].push_back(4);
    degree[4]++;
    prereq[2].push_back(1);
    degree[1]++;
    prereq[3].push_back(4);
    degree[4]++;
    prereq[3].push_back(5);
    degree[5]++;
    for (int i=0;i<10;i++){
        cin>>a>>b;
        if (a==b&&a==0){
            break;
        }
        prereq[a].push_back(b); //a before b
        degree[b]++;
    }

    priority_queue<int,vector<int>,greater<int>> pq;
    vector<int>seq;

    for (int i=0;i<degree.size();i++){
        if (degree[i]==0) pq.push(i);


    }
    while(!pq.empty()){
        int cur=pq.top();
        pq.pop();
        seq.push_back(cur);
        
        for (int x:prereq[cur]){
            degree[x]--;
            if (degree[x]==0){
                pq.push(x);
            }

        }
    }
    if (seq.size()-1!=7){
        
        cout<<"Cannot complete these tasks. Going to bed."<<endl;
    }else{
        for (int i=1;i<seq.size();i++){
            cout<<seq[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
