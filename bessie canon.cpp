#include <bits/stdc++.h>
using namespace std;

struct fuck{
  int type;
  int value;
};

int main(){
  int n,s;
  cin>>n>>s;
  int t,v;
  
  vector<fuck>line(n+1);
  vector<bool>broken(n+1,false);

  for (int i=1;i<n+1;i++){
    cin>>t>>v;
    line[i].type=t;
    line[i].value=v;
    
  }

  long long p=1;
  int d=1;
  int pos=s;

  int count=0;
  set<tuple<int,int,long long>>visited;//position, diretion, power

  while(pos>=1&&pos<n+1){
    auto state=make_tuple(pos,d,p);
    if(visited.count(state)==true){
      break;
    }

    visited.insert(state);

    if (line[pos].type==1){//target
      if (p>=line[pos].value&&broken[pos]==false){
        count++;
        broken[pos]=true;
        
      }
    }else{//pad
      p+=line[pos].value;
      d*=-1;
      
    }

    pos+=d*p;
  }

  cout<<count<<endl;
}
