#include <bits/stdc++.h>
using namespace std;


int main(){
    //freopen("sleepy.in","r",stdin);
    //freopen("sleepy.out","w",stdout);

    //AABbCcddEe
    //0123456789
    int n;
    string a,b;

    cin>>a>>b;
    cin>>n;
    vector<string>res;

    for (int v=0;v<n;v++){
        string bb;
        cin>>bb;

        bool match=true;
        for(int i=0;i<5;i++){
            int pos=i*2;
            if (isupper(bb[i])&&(bb[i]==a[pos]||bb[i]==a[pos+1]||bb[i]==b[pos]||bb[i]==b[pos+1])){
                
                continue;
            
            }else if ((!isupper(bb[i]))&&(bb[i]==a[pos]||bb[i]==a[pos+1])&&(bb[i]==b[pos]||bb[i]==b[pos+1])){
                
                continue;
            }else{
                match=false;
                break;
            }
            
        }
        if (match==false){
            res.push_back("Not their baby!");
        }else{
            res.push_back("Possible baby.");
        }

    }
    for (auto i:res){
        cout<<i<<endl;
    }

}
