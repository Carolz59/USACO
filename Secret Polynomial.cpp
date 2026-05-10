#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin>>n;
    while(n--){
        long long a,b;
        cin>>a>>b;
        if (a==0&&b==0){
            cout<<0<<endl;
            continue;
        }
        if (a<=0||b<=0){
            cout<<"IMPOSSIBLE"<<endl;
            continue;
        }

        
        if (a==1){
            if (b==1){
                cout<<"AMBIGUOUS"<<endl;
                continue;
            }else{
                cout<<"IMPOSSIBLE"<<endl;
                continue;
            }
            
        }
        if (a==b){
            cout<<"AMBIGUOUS"<<endl;
            continue;
        }
        vector<long long>cof;
        long long tot=0;
        while (b>=1){
            cof.push_back(b%a);
            tot+=b%a;
            b/=a;
            
            
        }
        reverse(cof.begin(),cof.end());

        

        if (tot!=a){
            cout<<"IMPOSSIBLE"<<endl;
            continue;
        }
        
        for (auto u:cof){
            cout<<u<<" ";
        }
        cout<<endl;

        
    }
}
