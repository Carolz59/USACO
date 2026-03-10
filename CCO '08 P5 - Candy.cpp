#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    vector<int>num(n),cal(n);
    int tot=0;

    for (int i=0;i<n;i++){
        cin>>num[i]>>cal[i];
        tot+=num[i]*cal[i];
    }

    int half=tot/2;
    vector<bool>dp(half+1,false);
    dp[0]=true;

    for (int i=0;i<n;i++){
        int am=num[i];
        int ca=cal[i];

        for (int j=0;j<am;j++){
            for (int k=half;k>=ca;k--){
                if (dp[k-ca]){
                    dp[k]=true;
                }
            }
        }
    }

    for (int i=half+1;i>=0;i--){
        if (dp[i]==true){
            cout<<tot-(i*2);
            break;
        }
    }
}
