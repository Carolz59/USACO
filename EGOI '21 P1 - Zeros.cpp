#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a,b;
    cin>>a>>b;

    long long two=0;
    long long five=0;

    long long powtwo=1;
    long long powfive=1;
    while (true){
        powtwo*=2;
        if (powtwo>b){
            break;
        }
        if (b/powtwo-(a-1)/powtwo>0){
            two++;
        }
    }
    while (true){
        powfive*=5;
        if (powfive>b){
            break;
        }
        if (b/powfive-(a-1)/powfive>0){
            five++;
        }
    }

    cout<<min(two,five);


}
