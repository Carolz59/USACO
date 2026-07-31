#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,k;
    cin>>n>>k;
    int diff[1002][1002]={};
    int a[1002][1002]={};
    for (int i=0;i<n;i++){
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        diff[y1][x1]++;
        diff[y2][x1]--;
        diff[y1][x2]--;
        diff[y2][x2]++;
    }

    for (int i=0;i<=1001;i++){
        for (int j=0;j<=1001;j++){
            a[i][j]=diff[i][j];
            if(i>0)a[i][j]+=a[i-1][j];
            if(j>0)a[i][j]+=a[i][j-1];
            if(i>0&&j>0)a[i][j]-=a[i-1][j-1];
        }
    }

    long long cnt=0;
    for (int i=0;i<=1001;i++){
        for (int j=0;j<=1001;j++){
            if (a[i][j]==k){
                cnt++;
            }
        }
    }
    cout<<cnt;


}
