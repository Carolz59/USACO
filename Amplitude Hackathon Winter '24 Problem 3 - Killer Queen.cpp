#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int>dro(10),q(10);

    for (int i=0;i<10;i++){
        cin>>dro[i];
    }
    for (int i=0;i<10;i++){
        cin>>q[i];
    }


    int ans=INT_MAX;
    for (int a=0;a<6;a++){
        for (int b=a+1;b<7;b++){
            for (int c=b+1;c<8;c++){
                for (int d=c+1;d<9;d++){
                    for (int e=d+1;e<10;e++){
                        vector<bool>used(10,false);
                        used[a]=true;
                        used[b]=true;
                        used[c]=true;
                        used[d]=true;
                        used[e]=true;
                        vector<int>other,cur;
                        for (int i=0;i<10;i++){
                            if (!used[i]){
                                other.push_back(i);
                            }else{
                                cur.push_back(i);
                            }
                        }
                        int tot1=dro[a]+dro[b]+dro[c]+dro[d]+dro[e];
                        int tot2=dro[other[0]]+dro[other[1]]+dro[other[2]]+dro[other[3]]+dro[other[4]];
                        for (int i=0;i<5;i++){
                            int team1=tot1+(q[cur[i]]-dro[cur[i]]);
                            for (int j=0;j<5;j++){
                                int team2=tot2+(q[other[j]]-dro[other[j]]);
                                ans=min(ans,abs(team1-team2));

                            }
                        }
                    }
                }
            }
        }
    }

    cout<<ans;
    

}
