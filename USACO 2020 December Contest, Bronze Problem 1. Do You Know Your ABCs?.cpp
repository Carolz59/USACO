#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector<int>seq;
    for (int i=0;i<7;i++){
        cin>>n;
        seq.push_back(n);

    }
    sort(seq.begin(),seq.end());

    int a=seq[0];
    int b=seq[1];
    int c=seq[6]-a-b;

    cout<<a<<" "<<b<<" "<<c;


}
