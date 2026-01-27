#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,r;
    cin>>n;
    map<long long,long long>price;
    long long tot=0;

    for (int i=0;i<n;i++){
        long long p; cin>>p;
        price[p]++;
        tot+=p;
    }

    cin>>r;
    long long ref=0;
    for (int i=0;i<r;i++){
        string op;
        cin>>op;
        long long am;
        if (op=="INFLATION"){
            cin>>am;
            ref+=am;
            tot+=n*am;

        }else{
            long long targ;
            cin>>targ>>am;
            long long old=targ-ref;
            long long newi=am-ref;

            if (price.count(old)){
                long long freq=price[targ-ref];
                tot-=targ*freq;
                tot+=am*freq;
                price.erase(old);
                price[newi]+=freq;

            }
            
        }

        cout<<tot<<endl;;
    }
}
