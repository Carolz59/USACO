#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m,a,b;
  cin>>n>>m;
  map<int,set<int>>graph;
  for(int i=0;i<m;i++){
    cin>>a>>b;
    graph[a].insert(b);
    graph[b].insert(a);
  }
  vector<int>femboy(n+1,0);

  for (int i=1;i<n+1;i++){
    set<int>used;

    for (auto&nei:graph[i]){
      if (femboy[nei]!=0){
        used.insert(femboy[nei]);
      }
    }
    for(int f=1;f<5;f++){
      if (!used.count(f)){
        femboy[i]=f;
        break;
      }
    }

  }

  for (auto&u:femboy){
    if (u!=0){
      cout<<u;
    }
  }


}
