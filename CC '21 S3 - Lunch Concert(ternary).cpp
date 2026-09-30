#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cin>>n;

    vector<tuple<long long,long long,long long>>v(n);

    for (int i=0;i<n;i++){
        long long a,b,c;
        cin>>a>>b>>c;
        v[i]={a,b,c};
    }

    long long l=0;
    long long r=1e9;

    while(r-l>2){
        long long m1=l+(r-l)/3;
        long long m2=r-(r-l)/3;
        long long tot1=0, tot2=0;
        for (int i=0;i<n;i++){
            auto [p,w,e]=v[i];
            if(p+e<m1){
                tot1+=w*(m1-p-e);
            }else if(p-e>m1){
                tot1+=w*(p-e-m1);
            }

            if(p+e<m2){
                tot2+=w*(m2-p-e);
            }else if(p-e>m2){
                tot2+=w*(p-e-m2);
            }


        }
        if (tot1>tot2){
            l=m1+1;
            
        }else{
            r=m2;
        }
    }

    long long ans=LLONG_MAX;
    for (int i=l;i<=r;i++){
        long long t=0;
        for (int j=0;j<n;j++){
            auto [p,w,e]=v[j];
            if(p+e<i){
                t+=w*(i-p-e);
            }else if(p-e>i){
                t+=w*(p-e-i);
            }
            
        }
        if (t<ans){
            ans=t;
        }
    }
    cout<<ans;
    
}
