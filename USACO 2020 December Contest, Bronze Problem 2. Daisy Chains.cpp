#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>seq;
    for (int i=0;i<n;i++){
        int x;
        cin>>x;
        seq.push_back(x);

    }
    
    int cnt=0;
    
    for (int i=0;i<n;i++){
        int sum=0;
        for (int j=0;i+j<n;j++){
            sum+=seq[i+j];
            if (sum%(j+1)==0){
                int avg=sum/int(j+1);
                for (int p=i;p<=i+j;p++){
                if (seq[p]==avg){
                    cnt++;
                    break;
                }
            }
            }
            
        }
    }
    cout<<cnt;


}
