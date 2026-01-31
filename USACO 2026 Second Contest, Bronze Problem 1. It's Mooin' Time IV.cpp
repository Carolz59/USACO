#include <bits/stdc++.h>
using namespace std;

//testing a theory

int main(){
    int t,k;
    cin>>t>>k;

    for (int i=0;i<t;i++){
        int n;
        cin>>n;
        string s;
        cin>>s;

        cout<<"YES"<<endl;
        if (k==0){
            continue;
        }
        bool flip=false;
        string ans;

        for (int j=n-1;j>=0;j--){
            if (!flip){
                if (s[j]=='M'){
                    ans+="M";
                }else{
                    ans+="O";
                    flip=true;
                }

            }else{
                if (s[j]=='O'){
                    ans+="M";
                }else{
                    ans+="O";
                    flip=false;

                }
            }
        }
        reverse(ans.begin(),ans.end());
        cout<<ans<<endl;

    }

    
    
}
