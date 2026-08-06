#include<bits/stdc++.h>
using namespace std;

long long n;
vector<long long>seg,v,lazy;
void build(long long node,long long l,long long r){
    if (l==r){
        seg[node]=v[l];
        return;
    }
    long long mid=(l+r)/2;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    seg[node]=seg[node*2]+seg[node*2+1];
}

void push(long long node,long long l,long long r){
    if (l==r||seg[node]==0){
        return;
    }
    long long mid=(l+r)/2;
    seg[node*2]+=lazy[node]*(mid-l+1);
    seg[node*2+1]+=lazy[node]*(r-mid);
    lazy[node*2]+=lazy[node];
    lazy[node*2+1]+=lazy[node];
    lazy[node]=0;

}

long long find(long long node,long long l,long long r,long long pos){
    if(l==r){
        return seg[node];
    }
    push(node,l,r);
    long long mid=(l+r)/2;
    if (pos<=mid){
        return find(node*2,l,mid,pos);
    }else{
        return find(node*2+1,mid+1,r,pos);
    }
}


void update(long long node,long long l,long long r,long long ql,long long qr,long long val){
    if(qr<l||ql>r){
        return;
    }
    if (ql<=l&&qr>=r){
        seg[node]+=val*(r-l+1);
        lazy[node]+=val;
        return;
    }
    push(node,l,r);
    long long mid=(l+r)/2;
    update(node*2,l,mid,ql,qr,val);
    update(node*2+1,mid+1,r,ql,qr,val);

    seg[node]=seg[node*2]+seg[node*2+1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long q;
    cin>>n>>q;
    seg.assign(4*n+4,0);
    v.resize(n+1);
    lazy.resize(4*n+4,0);
    for (int i=0;i<n;i++){
        cin>>v[i+1];
    }
    build(1,1,n);
    while (q--){
        int t;
        cin>>t;
        if (t==1){
            long long a,b,u;
            cin>>a>>b>>u;
            update(1,1,n,a,b,u);

        }else{
            long long p;
            cin>>p;
            cout<<find(1,1,n,p)<<endl;

        }
    }


}
