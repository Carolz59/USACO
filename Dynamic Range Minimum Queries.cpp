#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>seg;
vector<int>a;
void build(int node,int l,int r){
    if (l==r){
        seg[node]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    seg[node]=min(seg[node*2],seg[node*2+1]);
}

int q(int node, int l,int r,int ql,int qr){
    if (qr<l||ql>r){
        return INT_MAX/2;
    }
    if(ql<=l&&qr>=r){
        return seg[node];
    }
    int mid=(l+r)/2;
    return min(q(node*2,l,mid,ql,qr),q(node*2+1,mid+1,r,ql,qr));
}

void update(int node,int l,int r,int pos,int val){
    if (l==r){
        seg[node]=val;
        return;
    }
    int mid=(l+r)/2;
    if (pos<=mid){
        update(node*2,l,mid,pos,val);
    }else{
        update(node*2+1,mid+1,r,pos,val);
    }
    seg[node]=min(seg[node*2],seg[node*2+1]);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long z;
    cin>>n>>z;
    seg.assign(n*4,INT_MAX/2);
    a.assign(n+1,0);
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }

    build(1,1,n);

    while (z--){
        int t,x,y;
        cin>>t>>x>>y;
        if (t==1){
            update(1,1,n,x,y);

        }else{
            cout<<q(1,1,n,x,y)<<endl;
        }
    }


}
