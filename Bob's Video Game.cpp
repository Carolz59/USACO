#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,t;
    cin>>n>>m>>t;

    vector<vector<int>>dist(n+1,vector<int>(n+1));

    for (int i=1;i<n+1;i++){
        for (int j=1;j<n+1;j++){
            if (i==j){
                dist[i][j]=0;
            }else{
                dist[i][j]=INT_MAX;
            }
        }
    }

    for (int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        dist[a][b]=c;
    }
    for (int k=1;k<n+1;k++){
        for (int i=1;i<n+1;i++){
            for (int j=1;j<n+1;j++){
                dist[i][j]=min(max(dist[i][k],dist[k][j]),dist[i][j]);
            }
        }
    }

    for (int i=0;i<t;i++){
        int a,b;
        cin>>a>>b;
        
        if (dist[a][b]==INT_MAX){
            cout<<-1<<endl;
        }else{
            cout<<dist[a][b]<<endl;
        }
    }
}
