#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int c;
    cin>>n;
    vector<vector<int>>tiles(2);
    
    int l=0;


    for (int i=0;i<n;i++){
        cin>>c;
        tiles[0].push_back(c);
    }
    for (int i=0;i<n;i++){
        cin>>c;
        tiles[1].push_back(c);
    }
    

    for (int y=0;y<2;y++){
        
        for(int x=0;x<n;x++){
            
            if (tiles[y][x]==1){
                
                l+=3;

                //<==B
                if (x>0&&tiles[y][x-1]==1){
                    l-=1;
                //B==>
                }
                if(x<n-1&&tiles[y][x+1]==1){
                    l-=1;
                //OO
                //||
                // V
                }
                if(y==0&&(x+y)%2==0&&tiles[y+1][x]==1){
                    l-=1;
                //^
                //||
                //OO
                }
                if (y==1&&(x+y)%2==1&&tiles[y-1][x]==1){
                    l-=1;
                }
            }
        }
    }
    cout<<l<<endl;
}
