#include <bits/stdc++.h>
using namespace std;

int main(){
    string n;
    cin>>n;
    string note,am;
    char op;
    vector<string>res;
    for (int i=0;i<n.size();i++){
        if (isdigit(n[i])){
            am+=n[i];
        }else if(n[i]=='+'||n[i]=='-'){
            op=n[i];
        }else{
            note+=n[i];
        }

        if ((i<=n.size()-2&&isdigit(n[i])&&!isdigit(n[i+1]))||i==n.size()-1){
            string out="";
            out+=note;
            if (op=='+'){
                out+=" tighten ";
            }else{
                out+=" loosen ";
            }

            out+=am;
            res.push_back(out);
            note="";
            am="";
        }

    }
    for (auto u:res){
        cout<<u<<endl;
    }
}
