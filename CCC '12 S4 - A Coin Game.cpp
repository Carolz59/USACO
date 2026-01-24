#include <bits/stdc++.h>
using namespace std;

int n;
vector<string>start;
vector<int>dis;

int base2(vector<string>board){
    int base=0;

    for (int i=0;i<n;i++){
        for (auto u:board[i]){
            int coin=u-'1';
            base+=i*pow(n,coin);
            
        }
    }
    return base;
}

vector<string> makemove(int p1,int p2,vector<string>board){
    vector<string>copy=board;
    if (copy.empty()){
        return board;
    }
    char top=copy[p1][0];

    copy[p2]=top+copy[p2];
    copy[p1]=copy[p1].substr(1);

    if (p2<p1&&top-'0'==n){
        return board;
    }
    return copy;

}

bool done(vector<string>board){
    for (int i=0;i<n;i++){
        if (board[i].size()!=1||board[i][0]-'0'!=i+1){
            return false;
        }
    }
    return true;

}

int bfs(){


    queue<vector<string>>q;
    q.push(start);
    dis[base2(start)]=0;

    while(!q.empty()){
        auto cur=q.front();
        q.pop();
        int curdist=dis[base2(cur)];

        if (done(cur)){
            return curdist;
        }

        for (int i=0;i<=n-2;i++){
            //right
            if ((!cur[i].empty())&&(cur[i+1].empty()||cur[i+1][0]>cur[i][0])){
                vector<string> next=makemove(i,i+1,cur);
                int id=base2(next);

                if (dis[id]!=-1){
                    continue;

                }
                dis[id]=curdist+1;
                q.push(next);
            }
        }
        for (int i=1;i<n;i++){
            //left
            if ((!cur[i].empty())&&(cur[i-1].empty()||cur[i-1][0]>cur[i][0])){
                vector<string> next=makemove(i,i-1,cur);
                int id=base2(next);
                if (dis[id]!=-1){
                    continue;

                }
                dis[id]=curdist+1;
                q.push(next);
            }

        }


    }

    return -1; 
}


int main(){
    while (true){
        cin>>n;
        if (n==0){
            return 0;
        }
        start.resize(n);
        int maxstate=pow(n,n);
        dis.assign(maxstate,-1);
        for (int i=0;i<n;i++){
            cin>>start[i];
        }
        int res=bfs();
        if (res!=-1){
            cout<< res<<endl;
        }else{
            cout<< "IMPOSSIBLE"<<endl;
    }

    }

}
