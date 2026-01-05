#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<string>qualify;

    for (int i=0;i<n;i++){
        int y,m,d;
        cin>>y>>m>>d;

        bool valid=true;

        if (2007-y<18){
            valid=false;

        }
        if (2007-y==18&&m>2){
            valid=false;

        }
        if (2007-y==18&&m==2&&d>27){
            valid=false;

        }
        if (valid){
            qualify.push_back("Yes");
        }else{
            qualify.push_back("No");
        }

    }
    for (auto i:qualify){
        cout<<i<<endl;
    }
}
