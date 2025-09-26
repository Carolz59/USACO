#include<bits/stdc++.h>

using namespace std;

int main(){
    int lines,size;
    char letter;
    cin>>lines>>size;

    vector<int>freq(26,0);
    vector<bool>heavy(26,0);
    vector<char>cur;
    bool yes= true;
    for (int i=0;i<lines;i++){
        for (int j=0;j<size;j++){
            //get freq
            cin>>letter;
            cur.push_back(letter);
            freq[letter-'a']++;
            if (freq[letter-'a']>1){
                heavy[letter-'a']=true;
            }
            
            
        }
        
        for (int x=1;x<cur.size();x++){
            if (heavy[cur[x]-'a']==heavy[cur[x-1]-'a']){
                yes=false;
                break;
            }
        }
        cout << (yes ?'T':'F') << "\n";
        fill(freq.begin(), freq.end(), 0);
        fill(heavy.begin(), heavy.end(), false);
        cur.clear();
        yes=true;
        
    }
    
    

}
