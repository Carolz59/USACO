#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin>>n>>s;

    int total=0;

    if (s[0]==s[n-1]) {
        total+=1;

        int l=0,r=n-1;

        while (l<n && s[l]==s[0]) l++;
        while (r>=0 && s[r]==s[0]) r--;

        if (l<=r) {
            char prev='.';
            for (int i=l;i<=r;i++) {
                if (s[i]!=prev) {
                    prev=s[i];
                    total++;
                }
            }
        }

        cout<<total<<endl;
    } else {
        cout<<n<<endl;
    }
}
