#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,k;
    string s;
    cin>>n>>k>>s;
    int cnt=0;
    int score=0;
    bool no=false;
    for (int i=0;i<n;i++){
        if (s[i]=='S'){
            cnt++;
            score++;
            no=false;
        }else if(s[i]=='P'){
            if (no){
                cout<<"NO";
                return 0;
            }
            cnt++;
            score+=2;
            no=true;
        }else{
            cnt=0;
            no=false;
        }

        if (cnt>k){
            cout<<"NO";
            return 0;
        }
    }

    cout<<"YES"<<endl<<score;

    
}
