#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

int n,t;
vector<pair<int,int>> v;

bool c(int m){
    if(m==0)return true;
    if(m>n)return false;

    set<int> rs;
    set<int> cs;
    
    rs.insert(1);
    rs.insert(n-m+1);
    cs.insert(1);
    cs.insert(n-m+1);

    for(const auto& tree:v){
        rs.insert(tree.first + 1);
        cs.insert(tree.second + 1);
        
        rs.insert(tree.first - m + 1);
        cs.insert(tree.second - m + 1);
    }
    
    for(int r:rs){
        for(int c:cs){
            if(r<1||c<1)continue;
            if(r+m-1>n||c+m-1>n)continue;

            bool clear=true;
            
            for(const auto& tree:v){
                int tr=tree.first;
                int tc=tree.second;

                if(tr>=r&&tr<=r+m-1&&tc>=c&&tc<=c+m-1){
                    clear=false;
                    break;
                }
            }

            if(clear)return true;
        }
    }

    return false;
}

void solve(){
    cin>>n>>t;
    v.resize(t);
    for(int i=0;i<t;++i){
        cin>>v[i].first>>v[i].second;
    }

    int l=1,r=n;
    int ans=0;

    while(l<=r){
        int mid=l+(r-l)/2;
        if(c(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }

    cout<<ans<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
