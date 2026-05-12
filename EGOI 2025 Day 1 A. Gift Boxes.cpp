#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t,n;
    cin>>t>>n;
    vector<int>v(n);
    vector<int>p(t),s(t);

    for (int i=0;i<n;i++){
        cin>>v[i];
        s[v[i]]++;
    }

    int r=-1;

    int conf=0;
    for (int i=0;i<t;i++){
        if (s[i]>=2){
            conf++;
        }
    }

    int best=n;
    int cur=n;
    int bestl=n-1;
    int bestr=0;

    for (int l=0;l<n;l++){

        while (r<l-1){
            r++;
            if (s[v[r]]+p[v[r]]>=2){
                conf--;
            
            }
            s[v[r]]--;

            if (s[v[r]]+p[v[r]]>=2){
                conf++;
            }

        }
        
        while (r<n-1&&conf!=0){
            r++;
            
            if (s[v[r]]+p[v[r]]>=2){
                conf--;
            
            }
            s[v[r]]--;

            if (s[v[r]]+p[v[r]]>=2){
                conf++;
            }

            

            }
            cur=r-l+1;
            if (cur<best&&conf==0){
                bestl=l;
                bestr=r;
                best=cur;
            }
            if (s[v[l]]+p[v[l]]>=2){
                conf--;
            
            }
            s[v[l]]++;

            if (s[v[l]]+p[v[l]]>=2){
                conf++;
            }
        
        
    }

    cout<<bestl<<" "<<bestr;
    


}
