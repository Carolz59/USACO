#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n = 10000;
vector<vector<int>> adj(n);
vector<bool>v(n, false);
vector<int> seq;

void dfs(int s){
  if (v[s]==true){
    
    return;
  }
  v[s]=true;
  seq.push_back(s);
  for (int i = 0; i < adj[s].size(); i++){
    dfs(adj[s][i]);
    
  }
}

int main(){
  adj[1].push_back(2);
  adj[1].push_back(7);
  adj[1].push_back(8);
  adj[2].push_back(3);
  adj[2].push_back(6);
  adj[3].push_back(4);
  adj[3].push_back(5);
  dfs(1);
  for(int i = 0; i<seq.size();i++){
    cout<<seq[i]<<endl;
  }
}
