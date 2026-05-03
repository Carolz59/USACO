#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int l,s;
    cin>>l>>s;
    map<char,int>f;

    string n;
    cin>>n;
    for (int i=0;i<l;i++){
        if (n[i]!='*'){
            f[n[i]]++;
        }
    }

    long long top=1;
        for (int i=l;i>=2;i--){
            top*=i;

        }

    

    if (s==0){
        int bot=1;
        for (char i='a';i<='z';i++){
            int freq=f[i];
            for (int k=freq;k>=2;k--){
                    bot*=k;
                }
            
        }
        cout<<top/bot<<endl;
        return 0;
    }

    if (s==1){
        long long tot=0;
        
        for (char i='a';i<='z';i++){
            f[i]++;
            long long bot=1;
            for (char j='a';j<='z';j++){
                int freq=f[j];
                for (int k=freq;k>=2;k--){
                    bot*=k;
                }
            }
            tot+=top/bot;
            f[i]--;
        }
        cout<<tot<<endl;
        return 0;
    }

    long long tot=0;
    for (char i='a';i<='z';i++){
        f[i]++;
        
        for (char j=i;j<='z';j++){
            long long bot=1;
            f[j]++;
            for (char k='a';k<='z';k++){
                int freq=f[k];
                for (int z=freq;z>=2;z--){
                    bot*=z;
                }
            }
            tot+=top/bot;
            f[j]--;
        }
        f[i]--;
    }

    cout<<tot<<endl;
    return 0;




    
}
