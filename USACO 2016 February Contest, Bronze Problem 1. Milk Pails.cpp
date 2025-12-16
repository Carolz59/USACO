#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    int x,y,m;
    cin>>x>>y>>m;



    int ma=0;

    for (int i=0;i<=(m/x);i++){
        int rest=m-(x*i);
        int numy=rest/y;
        int n=(x*i)+(numy*y);
        if (n>ma){
            ma=n;
        }
    }
    cout<<ma;
}
