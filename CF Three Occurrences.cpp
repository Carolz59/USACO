#include<bits/stdc++.h>
using namespace std;

long long n;
long long mod=1000000007;
long long base=31;
map<long long,long long>rem;
vector<uint64_t>l1,l2;

mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    vector<long long>v(n+1);
    l1.resize(n+1);
    l2.resize(n+1);

    for (int i=1;i<=n;i++){
        cin>>v[i];
        l1[i]=gen();
        l2[i]=gen();

    }
    
    long long ans=0;
    long long l=1;
    uint64_t cur=0;
    map<uint64_t,deque<long long>>mp;
    map<long long,long long>cnt;
    mp[0].push_back(0);
    for (long long r=1;r<=n;r++){
        cnt[v[r]]++;
        while (cnt[v[r]]==4){
            cnt[v[l]]--;
            l++;
        }
        if (rem[v[r]]==0){
            rem[v[r]]=1;
            cur^=l1[v[r]];

        }else if (rem[v[r]]==1){
            rem[v[r]]=2;
            cur^=l1[v[r]];
            cur^=l2[v[r]];

        }else{
            rem[v[r]]=0;
            cur^=l2[v[r]];
        }

        while (!mp[cur].empty()&&mp[cur].front()<l-1){
            mp[cur].pop_front();
        }
        mp[cur].push_back(r);
        ans+=mp[cur].size()-1;
    }
    cout<<ans;







}
