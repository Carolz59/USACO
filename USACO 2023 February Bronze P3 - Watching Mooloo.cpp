#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("notlast.in","r",stdin);
    //freopen("notlast.out","w",stdout);

    long long n,k;
    vector<long long>days;
    cin>>n>>k;
    for (long long i=0;i<n;i++){
        long long day;
        cin>>day;
        days.push_back(day);

    }
    sort(days.begin(),days.end());

    long long mony=k+1;
    

    if (n==1){
        cout<<mony<<endl;
        return 0;
    }

    for (long long i=1;i<n;i++){
        long long ex=k+1;
        long long cont=days[i]-days[i-1];
        mony+=min(ex,cont);
    }
    cout<<mony;


}
