#include<bits/stdc++.h>
using namespace std;


int main(){
    freopen("whereami.in", "r", stdin);  
    freopen("whereami.out", "w", stdout);
    
    int n;
    string s;
    cin>>n;
    cin>>s;
    

    for (int i=1;i<=n;i++){
        set<string>dup;
        bool work=true;
        for (int j=0;i+j<=n;j++){
            string sub=s.substr(j,i);
            if (dup.count(sub)==true){
                work=false;
                break;

            }
            dup.insert(sub);
        }
        if (work==true){
            cout<<i<<endl;
            return 0;
        }
    }


    
}
