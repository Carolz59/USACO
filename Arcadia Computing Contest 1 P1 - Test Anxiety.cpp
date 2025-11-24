#include <iostream>
using namespace std;

int main() {
    double score,n;
    cin>>score>>n;
    double tot=score*n;
    double res=((n+1)*80)-tot;
    if (res<=100&&res>0){
        cout<<res;
    }else if(res<=0){
        cout<<0;
    }else{
        cout<<-1;
    }

}
