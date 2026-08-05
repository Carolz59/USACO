#include<bits/stdc++.h>
using namespace std;

long long n;
vector<long long>seg,a;
void build(long long node,long long l,long long r){
    if (l==r){
        seg[node]=a[l];
        return;
    }
    long long mid=(l+r)/2;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    seg[node]=max(seg[node*2],seg[node*2+1]);

}

long long query(long long node,long long l,long long r,long long ql,long long qr){
    if(ql>r||qr<l){
        return 0;
    }
    if(ql<=l&&qr>=r){
        return seg[node];
    }
    long long mid=(l+r)/2;
    return max(query(node*2,l,mid,ql,qr),query(node*2+1,mid+1,r,ql,qr));
}

void update(long long node,long long l,long long r,long long val,long long pos){
    if (l==r){
        seg[node]=val;
        return;
    }
    long long mid=(l+r)/2;
    if (pos<=mid){
        update(node*2,l,mid,val,pos);

    }else{
        update(node*2+1,mid+1,r,val,pos);
    }
    seg[node]=max(seg[node*2],seg[node*2+1]);
}
int main(){
    //i-j>ai, j<i-ai
    //i-j>aj, j+aj<i
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t;
    cin>>t;
    while (t--){
        long long s;
        cin>>s;
        long long ans=0;
        seg.assign(4*s,0);
        a.resize(s+1);
        vector<long long>dp(s+1);
        vector<pair<long long,long long>>v(s);
        for (long long i=1;i<=s;i++){
            cin>>a[i];
            v[i-1]={a[i]+i,i};

        }
        sort(v.begin(),v.end());
        long long cur=0;
        for (long long i=1;i<=s;i++){
            while (cur<s&&v[cur].first<i){
                update(1,1,s,dp[v[cur].second],v[cur].second);
                cur++;
            }
            long long curbest=0;
            long long z=i-a[i]-1;
            if (z>=1) curbest=query(1,1,s,1,z);
            dp[i]=curbest+a[i];
            ans=max(ans,dp[i]);

        }
        cout<<ans<<endl;

    }


}
