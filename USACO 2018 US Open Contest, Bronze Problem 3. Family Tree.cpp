#include <bits/stdc++.h>
using namespace std;

vector<string>mom(100),dau(100);
int n;

string maternity(string s){
    for (int i=0;i<n;i++){
        if (dau[i]==s){
            return mom[i];
        }
    }
    return "";
}

int ancestry(string a,string b){
    int gen=0;
    while (b!=""){
        if (a==b){
            return gen;
        }
        b=maternity(b);
        gen++;
    }
    return -1;
    
}



int lcagen(string a,string b){
    int l=0;
    string anc=a;
    while (anc!=""){
        if (ancestry(anc,b)!=-1){
            return l;
            break;
        }
        anc=maternity(anc);
        l++;
    }
    return -1;
}
string lcaname(string a,string b){
    string anc=a;
    while (anc!=""){
        if (ancestry(anc,b)!=-1){
            return anc;
        }
        anc=maternity(anc);
        
    }
    return "";
}

int main(){
    //freopen("family.in","r",stdin);
    //freopen("family.out","w",stdout);
    cin>>n;
    string cow1,cow2;
    cin>>cow1>>cow2;

    mom.resize(n);
    dau.resize(n);

    for (int i=0;i<n;i++){
        cin>>mom[i]>>dau[i];

    }

    //find lca
    int b=lcagen(cow1,cow2);
    string common=lcaname(cow1,cow2);
    int e=ancestry(common,cow2);

    if (common=="") {
        cout<<"NOT RELATED";
        return 0;
    }

    if (b==e&&e==1){
        cout<<"SIBLINGS";
    }else if(e>1&&b>1){
        cout<<"COUSINS";
    }else{
        if (e>b){
            swap(e,b);
            swap(cow1,cow2);
            
        }
        cout<<cow2<<" is the ";

        for (int i=0;i<b-2;i++){
            cout<<"great-";
        }

        if (b>1&&e==0){
            cout<<"grand-";
        }
        
        if (e==0){
            cout<<"mother ";
        }else{
            cout<<"aunt ";
        }
        cout<<"of "<<cow1;
    }



    
}
