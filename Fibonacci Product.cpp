#include<bits/stdc++.h>
using namespace std;

vector<long long>fib;
long long yes(long long x,long long start){

    if (x==1){
        return 1;
    }
    long long ways=0;

    for (long long i=start;i<(long long)fib.size();i++){
        if (fib[i]>x){
            break;
        }
        if (x%fib[i]==0){
            ways+=yes(x/fib[i],i);
        }
    }
    return ways;

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin>>n;

    
    fib.push_back(2);
    fib.push_back(3);
    long long cur=2;
    long long cur1=3;
    while (true){
        long long add=cur+cur1;
        if (add>1e18){
            break;
        }
        fib.push_back(add);
        cur=cur1;
        cur1=add;
    }

    while (n--){
        long long x;
        cin>>x;
        cout<<yes(x,0)<<endl;
    }
    
}
