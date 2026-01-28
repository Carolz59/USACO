#include <bits/stdc++.h>
using namespace std;


int main(){
    long long n,t;
    cin>>n>>t;

    vector<tuple<long long,long long,long long,long long>>ev;
    vector<long long>y;

    for (int i=0;i<n;i++){
        long long x1,y1,x2,y2,z;
        cin>>x1>>y1>>x2>>y2>>z;
        ev.push_back({x1,y1,y2,z});
        ev.push_back({x2,y1,y2,-z});

        y.push_back(y1);
        y.push_back(y2);

    }

    sort(ev.begin(),ev.end());
    sort(y.begin(),y.end());
    y.erase(unique(y.begin(),y.end()),y.end());

    long long markerx=0;
    long long yint=y.size()-1;
    vector<long long>cov(yint,0);
    long long area=0;

    for (auto [x1,y1,y2,z]:ev){
        //add area!!!!!
        long long dx=x1-markerx;
        for (int i=0;i<yint;i++){
            if (cov[i]>=t){
                area+=(y[i+1]-y[i])*dx;
            }
        }

        for (int i=0;i<yint;i++){
            //update da covvyyyy

            if (y1<=y[i]&&y2>=y[i+1]){
                cov[i]+=z;
            }
        }
        markerx=x1;

    }
    cout<<area;

}
