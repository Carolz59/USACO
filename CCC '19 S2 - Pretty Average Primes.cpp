#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

//(a+b)/2=x

bool isprime(int x){
    if (x==2){
        return true;
    }else if(x%2==0&&x!=2){
        return false;
    }

    for (int i=3;i<=sqrt(x);i+=2){
        if (x%i==0){
            return false;
        }
    }
    return true;
}

pair<int, int> avprime(int x){
    int tot=x*2;
    //check 2
    if (isprime(tot-2)){
        return make_pair(2,tot-2);
    }
    for (int i=3;i<x;i++){
        if (isprime(i)&&isprime(tot-i)){
            return make_pair(i,tot-i);
        }
    }
    return make_pair(0, 0);
}


int main(){
    int n;
    cin>>n;
    vector<int>nums;
    int a;

    for (int i=0;i<n;i++){
        cin>>a;
        nums.push_back(a);
    }

    //vector<pair<int,int>> results;


    for (int i=0;i<n;i++){
        cout<<avprime(nums[i]).first<<" "<<avprime(nums[i]).second<<endl;
    }



}
