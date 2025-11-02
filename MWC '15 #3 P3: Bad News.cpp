#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<char>> g;
int xm[8]={-1,-1,-1,0,0,1,1,1}, ym[8]={-1,0,1,-1,1,-1,0,1};

bool dfs(int x,int y,string&w,int i){
    if(i==w.size())return true;
    if(x<0||y<0||x>=n||y>=n)return false;
    if(g[x][y]!=w[i])return false;
    char t=g[x][y];
    g[x][y]='#';
    for(int d=0;d<8;d++)
        if(dfs(x+xm[d],y+ym[d],w,i+1)){
            g[x][y]=t;
            return true;
        }
    g[x][y]=t;
    return false;
}

bool findWord(string&w){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(g[i][j]==w[0]&&dfs(i,j,w,0))
                return true;
    return false;
}

int main(){
    int q;cin>>n>>q;
    g.assign(n,vector<char>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>g[i][j];
    while(q--){
        string w;cin>>w;
        cout<<(findWord(w)?"good puzzle!":"bad puzzle!")<<endl;
    }
}
