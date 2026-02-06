#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    vector<int>res;

    while (true){
        cin>>n>>m;
        if (n==m&&m==0){
            break;
        }

        vector<vector<char>>grid(n+1,vector<char>(m+1,'n'));
        vector<vector<int>>val(n+1,vector<int>(m+1,0));


        for (int i=1;i<=n;i++){
            string l;
            cin>>l;
            for (int j=1;j<=m;j++){
                grid[i][j]=l[j-1];
                if (grid[i][j]-'0'>=1&&grid[i][j]-'0'<=9){
                    val[i][j]=grid[i][j]-'0';
                }
            }
        }

        vector<vector<int>>up(n+1,vector<int>(m+1,INT_MIN));
        vector<vector<int>>down(n+1,vector<int>(m+1,INT_MIN));
        up[n][1]=val[n][1];

        for (int u=n-1;u>=1;u--){
            if (grid[u][1]=='*'){
                continue;
            }
            up[u][1]=up[u+1][1]+val[u][1];
        }

        for (int c=2;c<=m;c++){
            
            for (int r=1;r<=n;r++){
                if (grid[r][c]=='*'){
                    continue;
                }
                down[r][c]=max(max(up[r][c-1]+val[r][c],down[r][c-1]+val[r][c]),down[r][c]);
                
                if (r>1){
                    down[r][c]=max(down[r][c],down[r-1][c]+val[r][c]);
                }

            }

            for (int r=n;r>=1;r--){
                if (grid[r][c]=='*'){
                    continue;
                }
                up[r][c]=max(max(up[r][c-1]+val[r][c],down[r][c-1]+val[r][c]),up[r][c]);
                if (r<n){
                    up[r][c]=max(up[r][c],up[r+1][c]+val[r][c]);
                }

            }
        }
        res.push_back(max(up[n][m],down[n][m]));
        
    }

    for (auto u:res){
        cout<<u<<endl;
    }
    
}
