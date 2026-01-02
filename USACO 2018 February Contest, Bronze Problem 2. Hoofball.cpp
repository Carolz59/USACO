#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("hoofball.in","r",stdin);
    //freopen("hoofball.out","w",stdout);
    int n;
    cin>>n;

    vector<int>cows;
    vector<int>in(n);
    vector<int>to(n);

    for (int i=0;i<n;i++){
        int c;
        cin>>c;
        cows.push_back(c);
    }
    sort(cows.begin(),cows.end());

    int ans=0;
    for (int i=0;i<n;i++){
        if (i==0){
            in[i+1]++;
            to[i]=i+1;
        }else if (i==n-1){
            in[i-1]++;
            to[i]=i-1;
        }else{
            if ((abs(cows[i]-cows[i-1]))<=(abs(cows[i]-cows[i+1]))){
                in[i-1]++;
                to[i]=i-1;
            }else{
                in[i+1]++;
                to[i]=i+1;
            }

        }

    }
    

    for (int i=0;i<n;i++){
        if (in[i]==0){
            ans++;
            
        }
        
    }
    
    for (int i=0;i<n-1;i++){
        if (to[i]==i+1&&to[i+1]==i&&in[i]==in[i+1]&&in[i]==1){
            ans++;
        }
    }

    cout<<ans<<endl;
    
}
