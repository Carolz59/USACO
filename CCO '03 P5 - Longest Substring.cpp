#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int>v;

    while(true){
        int n;
        cin>>n;
        if (n==0){
            break;
        }
        v.push_back(n);

    }
    long long l=0;
    long long r=0;
    long long best=0;
    set<long long>seen;
    long long bl,br;

    while (r<v.size()){
        if (!seen.count(v[r])&&r<v.size()){
            seen.insert(v[r]);
            r++;
            if (r-l>best){
                best=seen.size();
                bl=l;
                br=r;
            }

        }else{
            seen.erase(v[l]);
            l++;
        }
        

        


        
    }

    for (int i=bl;i<br;i++){
        cout<<v[i]<<endl;
    }

    



}
