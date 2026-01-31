#include <iostream>
#include <vector>
using namespace std;

int n,k;
struct Move{int m,o1,o2;};


vector<Move>moves;


int maxlol=-1;

long long ways=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(!(cin>>n>>k)){
        return 0;
    }

    moves.reserve(k);

    for(int i=0;i<k;i++){
        int a,b,c;
        cin>>a>>b>>c;
        moves.push_back({a-1,b-1,c-1});
    }

    vector<vector<int>>f(n,vector<int>(1<<n,0));

    for(const auto &mv:moves){
        f[mv.m][(1<<mv.o1)|(1<<mv.o2)]++;
    }

    for(int m=0;m<n;m++){
        for(int i=0;i<n;i++){
            for(int mask=0;mask<(1<<n);mask++){
                if(mask&(1<<i)){
                    f[m][mask]+=f[m][mask^(1<<i)];
                }
            }
        }
    }

    int full_mask=(1<<n)-1;

    for(int board=0;board<(1<<n);board++){
        int score=0;
        int inv_board=full_mask^board;

        for(int m=0;m<n;m++){
            if(board&(1<<m)){
                score+=f[m][inv_board];
            }
        }


        if(score>maxlol){
            maxlol=score;
            ways=1;


        }


        else if(score==maxlol){
            ways++;


        }
    }


    cout<<maxlol<<" "<<ways<<endl;

    
}



