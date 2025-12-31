#include <bits/stdc++.h>
using namespace std;


int main(){
    //freopen("outofplace.in","r",stdin);
    //freopen("outofplace.out","w",stdout);
    long long n,w;
    cin>>n>>w;

    vector<long long>pcute,pwid;
    pcute.push_back(0);
    pwid.push_back(0);
    deque<long long>dq;
    dq.push_back(0);
    vector<long long>hist;

    for (int i=0;i<n;i++){
        char type; cin>>type;
        if (type=='D'){
            hist.pop_back();
            pcute.pop_back();
            pwid.pop_back();
            while (!dq.empty()&&dq.front()>=pcute.size()) dq.pop_front();
            

        }else{
            long long p,c;
            cin>>p>>c;
            pcute.push_back(pcute.back()+c);
            pwid.push_back(pwid.back()+p);
            auto it=lower_bound(pwid.begin(),pwid.end(),pwid.back()-w);
            long long start=it-pwid.begin();

            long long cute=pcute.back()-pcute[start];

            if (hist.empty()){
                hist.push_back(cute);

            }else{
                hist.push_back(max(hist.back(),cute));
            }

            cout<<hist.back()<<endl;
        }


    }


}
