#include<bits/stdc++.h>
using namespace std;

int n;
vector<int>cur;
int tot=0;

void dfs(int rem,int last){
    if (rem==0){
        //process this shit
        tot++;
        cout<<n<<"=";
        for (int i=0;i<cur.size();i++){
            cout<<cur[i];
            if (i!=cur.size()-1){
                cout<<"+";
            }
        }
        cout<<endl;
        return;
    }
    

    for (int i=last;i<=rem;i++){
        if (i==n){
            continue;
        }
        cur.push_back(i);
        dfs(rem-i,i);
        cur.pop_back();
        
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    dfs(n,1);
    cout<<"total="<<tot;

    
}
