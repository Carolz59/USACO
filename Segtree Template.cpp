#include<bits/stdc++.h>
using namespace std;
long long n;
vector<long long>seg;
vector<long long>a;
void build(long long node,long long l,long long r){
    if (l==r){
        seg[node]=a[l];
        return;
    }
    long long mid=(l+r)/2;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    seg[node]=(seg[node*2]+seg[node*2+1]);
}

long long q(long long node, long long l,long long r,long long ql,long long qr){
    if (qr<l||ql>r){
        return 0;
    }
    if(ql<=l&&qr>=r){
        return seg[node];
    }
    long long mid=(l+r)/2;
    return (q(node*2,l,mid,ql,qr)+q(node*2+1,mid+1,r,ql,qr));
}

void update(long long node,long long l,long long r,long long pos,long long val){
    if (l==r){
        seg[node]=val;
        return;
    }
    long long mid=(l+r)/2;
    if (pos<=mid){
        update(node*2,l,mid,pos,val);
    }else{
        update(node*2+1,mid+1,r,pos,val);
    }
    seg[node]=(seg[node*2]+seg[node*2+1]);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,z;
    cin>>n>>z;
    seg.resize(n*4);
    a.resize(n+1);
    for (long long i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,1,n);
    while (z--){
        long long t,x,y;
        cin>>t>>x>>y;
        if (t==1){
            update(1,1,n,x,y);
        }else{
            cout<<q(1,1,n,x,y)<<endl;;
        }

    }



}
