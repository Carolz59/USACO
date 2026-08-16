#include<bits/stdc++.h>
using namespace std;

long long n,x,ans=0;
vector<long long>a;
vector<long long>v;

void uh(long long i,long long j,long long sum){
    if (i==j){
        v.push_back(sum);
        return;
    }
    uh(i+1,j,sum);
    uh(i+1,j,sum+a[i]);

}
void duh(long long i,long long j,long long sum){
    if (i==j){
        ans+=1LL*(upper_bound(v.begin(),v.end(),x-sum)-lower_bound(v.begin(),v.end(),x-sum));
        return;
    }
    duh(i+1,j,sum);
    duh(i+1,j,sum+a[i]);

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>x;
    a.assign(n,0);
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    uh(0,n/2,0);
    sort(v.begin(),v.end());
    duh(n/2,n,0);
    cout<<ans;


    
    
}
