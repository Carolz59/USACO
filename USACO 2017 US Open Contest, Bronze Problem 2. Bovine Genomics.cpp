
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout); 

    int n,m;
    cin>>n>>m;
    vector<string>spot(n);
    vector<string>clear(n);

    for (int i=0;i<n;i++){
        cin>>spot[i];
    }
    for (int i=0;i<n;i++){
        cin>>clear[i];
    }

    
    int count=0;
    for (int i=0;i<m;i++){
        vector<vector<bool>>track(2,vector<bool>(4,false));
        for (int j=0;j<n;j++){
            if (spot[j][i]=='A') track[0][0]=true;
            if (spot[j][i]=='T') track[0][1]=true;
            if (spot[j][i]=='G') track[0][2]=true;
            if (spot[j][i]=='C') track[0][3]=true;
        }
        for (int j=0;j<n;j++){
            if (clear[j][i]=='A') track[1][0]=true;
            if (clear[j][i]=='T') track[1][1]=true;
            if (clear[j][i]=='G') track[1][2]=true;
            if (clear[j][i]=='C') track[1][3]=true;
        }
        bool determine=true;
        for (int k=0;k<4;k++){
            if (track[0][k]==track[1][k]&&track[1][k]==true){
                determine=false;
                break;
            }
            
        }
        if (determine==true) count++;
    }
    cout<<count;


}
