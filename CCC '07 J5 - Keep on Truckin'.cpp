#include <bits/stdc++.h>
using namespace std;

//0 1 5 2
//1 1   

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int ma,mi,a;
    cin>>mi>>ma>>a;
    vector<int>mot={0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
    

    for (int i=0;i<a;i++){
        int ex;
        cin>>ex;
        mot.push_back(ex);
    }

    sort(mot.begin(),mot.end());

    vector<long long>dp(mot.size(),0);
    dp[0]=1;

    for (int i=0;i<mot.size();i++){
        for (int j=i+1;j<mot.size();j++){
            if (mot[j]-mot[i]>ma){
                break;
            }
            if (mot[j]-mot[i]>=mi){
                dp[j]+=dp[i];
            }
        }
    }
    cout<<dp[mot.size()-1]<<endl;
}
