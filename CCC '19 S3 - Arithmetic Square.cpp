#include <bits/stdc++.h>
#define mt -1000001 
using namespace std;

vector<vector<int>>square(3,vector<int>(3));
int filled=0;
int diff;


bool valid(){

    
    for (int i=0;i<3;i++){
        if ((square[i][1]-square[i][0])!=(square[i][2]-square[i][1])){
            return false;
        }
        
    }

    for (int j=0;j<3;j++){
        if ((square[1][j]-square[0][j])!=(square[2][j]-square[1][j])){
            return false;
        }
    }
    return true;
}

bool full(){
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            if (square[i][j]==mt){
            return false;
        }
        }
    }
    return true;
}

bool fill(){
    vector<vector<bool>>change(3,vector<bool>(3,false));
    
    bool mod=true;

    while (!valid()&&mod){
        mod=false;
        for (int i=0;i<3;i++){
        int unknownidx=-1;
        int knownum=0;

        for (int j=0;j<3;j++){
            if (square[i][j]!=mt){
                knownum++;

            }else{
                unknownidx=j;

            }
            
        }
        if (knownum==2&&unknownidx==0){
                square[i][unknownidx]=(square[i][1]*2)-square[i][2];
                filled++;
                change[i][unknownidx]=true;
                mod=true;
                

            }else if (knownum==2&&unknownidx==1){
                square[i][unknownidx]=(square[i][0]+square[i][2])/2;
                filled++;
                change[i][unknownidx]=true;
                mod=true;
                

            }else if (knownum==2&&unknownidx==2){
                square[i][unknownidx]=(square[i][1]*2)-square[i][0];
                filled++;
                change[i][unknownidx]=true;  
                mod=true;              
            }

            

        
    }
    for (int j=0;j<3;j++){
        int unknownidx=-1;
        int knownum=0;

        for (int i=0;i<3;i++){
            if (square[i][j]!=mt){
                knownum++;
                

            }else{
                unknownidx=i;

            }
            
        }
        if (knownum==2&&unknownidx==0){
                square[unknownidx][j]=(square[1][j]*2)-square[2][j];
                filled++;
                change[unknownidx][j]=true;
                mod=true;
                

            }else if (knownum==2&&unknownidx==1){
                square[unknownidx][j]=(square[0][j]+square[2][j])/2;
                filled++;
                change[unknownidx][j]=true;
                mod=true;

            }else if (knownum==2&&unknownidx==2){
                square[unknownidx][j]=(square[1][j]*2)-square[0][j];
                filled++;
                change[unknownidx][j]=true;
                mod=true;
            }



        
    }
    }
    if (valid()){
        return true;
    }

    if (full()){
        for (int i=0;i<3;i++){
            for (int j=0;j<3;j++){
                if (change[i][j]){
                    square[i][j]=mt;
                }
            }
        }
        return false;
    }

    for (int i=0;i<3;i++){
        bool inf=false;
        int known=-1;

        for (int j=0;j<3;j++){
            if (square[i][j]==mt){
                inf =true;

            }else{
                known=j;
            }
        }
        auto ogsqr=square;
        auto ogcge=change;


        if (inf==true&&known!=-1){
            if (known==0){
                square[i][1]=square[i][0]+diff;
                square[i][2]=square[i][1]+diff;
                change[i][1]=true;
                change[i][2]=true;


            }else if (known==1){
                square[i][0]=square[i][1]-diff;
                square[i][2]=square[i][1]+diff;
                change[i][0]=true;
                change[i][2]=true;


            }else{
                square[i][1]=square[i][2]-diff;
                square[i][0]=square[i][1]-diff;

                change[i][1]=true;
                change[i][0]=true;

        }
            if (fill()){
                return true;
            }
            square=ogsqr;
            change=ogcge;




        }

        for (int j=0;j<3;j++){
            int known1=-1;
            bool inf1=false;
            for (int i=0;i<3;i++){
                if (square[i][j]==mt){
                    inf1 =true;

                }else{
                    known1=i;
                }
                auto ogsqr=square;
                auto ogcge=change;

                if (inf1&&known1!=-1){
                    if (known1 == 0) {
                        square[1][j] = square[0][j] + diff;
                        square[2][j] = square[1][j] + diff;
                    }
                    else if (known1 == 1) {
                        square[0][j] = square[1][j] - diff;
                        square[2][j] = square[1][j] + diff;
                    }else {
                        square[1][j] = square[2][j] - diff;
                        square[0][j] = square[1][j] - diff;
}
                    if (fill()){
                        return true;
                    }
                    square=ogsqr;
                change=ogcge;

                }


            }
        }
        return false;
        
    }


    


}




int main(){

    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            string s;
            cin>>s;

            if (s=="X"){
                square[i][j]=mt;
            }else{
                square[i][j]=stoi(s);
                filled++;
            }
        }
    }

    if (filled==0){
        for (int i=0;i<3;i++){
            cout<<"0 0 0"<<endl;
        }
        return 0;
    }


    if (filled==9){
        for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            cout<<square[i][j];
            if (j!=2){
                cout<<" ";
            }
        }
        cout<<endl;
    }
        return 0;

    }

    for (int i=0;i<100;i++){
        diff=i;

        if (fill()){
        for (int i=0;i<3;i++){
            for (int j=0;j<3;j++){
                cout<<square[i][j];
                if (j!=2){
                    cout<<" ";
            }
        }
        cout<<endl;
    }
        return 0;

    }

    }



}
