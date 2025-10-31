#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

int main(){
    string line;
    cin>>line;

    int v=0;

    for (int i=0;i<line.size();i++){
        if (line[i]=='V'){
            v++;
        }
    }

    int h=line.size()-v;

    bool vert,hort;

    if (v%2==0){
        vert=true;

    }else{
        vert=false;
    }

    if (h%2==0){
        hort=true;

    }else{
        hort=false;
    }

    if (vert==true&&hort==true){
        //same

        cout<<1<<" "<<2<<endl;
        cout<<3<<" "<<4;
    }else if (vert==true&&hort==false){
        //same vert diff hort
        cout<<3<<" "<<4<<endl;
        cout<<1<<" "<<2;
    }else if (vert==false&&hort==true){
        //same vert diff hort
        cout<<2<<" "<<1<<endl;
        cout<<4<<" "<<3;
    }else{
        cout<<4<<" "<<3<<endl;
        cout<<2<<" "<<1;
    }


}
