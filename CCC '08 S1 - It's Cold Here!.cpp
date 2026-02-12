#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string city;
    int temp;

    string c;
    int low=INT_MAX;

    while (true){
        cin>>city>>temp;
        if (temp<low){
            low=temp;
            c=city;
        }

        if (city=="Waterloo"){
            break;
        }

    }

    cout<<c;



    
    
    
}
