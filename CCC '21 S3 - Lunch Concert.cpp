#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<tuple<long long,long long,long long>>v;

    for (int i=0;i<n;i++){
        long long init,rang;
        long long rate;
        cin>>init>>rate>>rang;
        v.push_back({init,rate,rang});

    }

    long long l=0;
    long long r=1000000000;
 
    long long best=LLONG_MAX;
    long long summ=0;
    long long sumn=0;
    while (l<r){
        summ=0;
        sumn=0;
        long long mid=(l+r)/2;
        long long dist=0;
        long long dist2=0;
        for (auto [i,rat,rag]:v){
            dist=abs(i-mid);
            dist2=abs(i-(mid+1));

            if (dist>rag){
                summ+=(abs(dist-rag)*rat);
            }
            if (dist2>rag){
                sumn+=(abs(dist2-rag)*rat);
            }
            
        }
        if (summ>sumn){
            l=mid+1;
        }else{
            r=mid;
        }
        best=min({summ,sumn,best});
        
    }

    cout<<best;
    
}
