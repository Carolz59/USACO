#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;

    for (int d=0;d<t;d++){
        int n;
        cin>>n;
        stack<int>v;
        stack<int>st;
        for (int i=0;i<n;i++){
            int z;
            cin>>z;
            v.push(z);
        }

        int cur=1;
        int i=n-1;
        while (!v.empty()||!st.empty()){
            if (!v.empty()&&v.top()==cur){
                v.pop();
                cur++;
            }else if((!v.empty()&&v.top()!=cur)&&(st.empty()||st.top()!=cur)){
                int proc=v.top();
                v.pop();
                st.push(proc);
                
            }else if(!st.empty()&&st.top()==cur){
                st.pop();
                cur++;
            
            }else if((!v.empty()&&v.top()!=cur)&&(!st.empty()||st.top()!=cur)){
                break;
            }else if((v.empty())&&(!st.empty()||st.top()!=cur)){
                break;
            }
        }
        if (v.empty()&&st.empty()){
            cout<<"Y"<<endl;
        }else{
            cout<<"N"<<endl;
        }
    }
    
    
}
